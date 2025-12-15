#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>

#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

#include <QSet>


void Main_Window::on_create_pdf_pushButton_clicked()
{
    QDate startDate = ui->from_report_dateEdit->date();
    QDate endDate = ui->to_report_dateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "Date 'from' can`t be earlier than 'to'.");
        return;
    }

    QSqlQuery reportQuery = db.getContractReport(startDate, endDate);
    if (!reportQuery.isActive()) {
        QMessageBox::critical(this, "DB error", "Query error.");
        return;
    }

    if (!reportQuery.next()) {
        QMessageBox::information(this, "Report", "Report for this period (from " + startDate.toString("dd.MM.yyyy") + " to " + endDate.toString("dd.MM.yyyy") + ") not found any contracts.");
        return;
    }

    reportQuery.previous();

    QString defaultFileName = QString("Звіт_Контракти_%1_до_%2.pdf")
                                  .arg(startDate.toString("yyyyMMdd"), endDate.toString("yyyyMMdd"));

    QString filePath = QFileDialog::getSaveFileName(this, "Зберегти Звіт PDF", defaultFileName, "PDF Files (*.pdf)");

    if (filePath.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QPageLayout layout = printer.pageLayout();
    layout.setOrientation(QPageLayout::Landscape);
    printer.setPageLayout(layout);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "ERROR PDF", "Error with QPainter.");
        return;
    }

    int margin = 30;
    int currentY = margin;
    int lineHeight = 20;
    int rowHeight = 15;
    int pageHeight = printer.pageRect(QPrinter::DevicePixel).height();

    const int colWidths[] = {
        25, 50, 40, 65, 55, 55, 70, 50, 65, 60, 40, 40, 40
    };
    const QString headers[] = {
        "ID", "Клієнт", "Рік", "№ Авто", "Дата з", "Дата по", "Деталь",
        "Варт. Дет.", "Робітник", "Позиція", "Робота", "Варт. Роб.", "Заг. Варт."
    };
    const int numColumns = sizeof(colWidths) / sizeof(colWidths[0]);
    int tableWidth = 0;
    for (int width : colWidths) {
        tableWidth += width;
    }
    int endX = margin + tableWidth;

    auto drawHeaders = [&]() {
        painter.setFont(QFont("Arial", 7, QFont::Bold));
        int currentX = margin;

        for (int i = 0; i < numColumns; ++i) {
            Qt::Alignment alignment = (i == 11 || i == 12) ? Qt::AlignRight : Qt::AlignLeft;
            painter.drawText(currentX, currentY, colWidths[i], lineHeight, alignment, headers[i]);
            currentX += colWidths[i];
        }

        currentY += lineHeight;
        painter.drawLine(margin, currentY, endX, currentY);
        currentY += 10;
    };

    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(margin, currentY, "Розширений Звіт по Контрактах");
    currentY += 30;
    painter.setFont(QFont("Arial", 10));
    painter.drawText(margin, currentY, QString("Період: %1 — %2")
                                           .arg(startDate.toString("dd.MM.yyyy"), endDate.toString("dd.MM.yyyy")));
    currentY += 40;
    drawHeaders();

    double totalProfit = 0.0;
    QSet<QString> countedContractIds;
    QString previousId = "";


    while (reportQuery.next()) {
        if (currentY > pageHeight - margin - rowHeight) {
            printer.newPage();
            currentY = margin;
            drawHeaders();
        }

        painter.setFont(QFont("Arial", 7));
        int currentX = margin;

        QString id = reportQuery.value("ID").toString();

        bool isDuplicateRow = (id == previousId);

        QString client = isDuplicateRow ? "" : reportQuery.value("Client").toString();
        QString carYear = isDuplicateRow ? "" : reportQuery.value("Car year").toString();
        QString carNumber = isDuplicateRow ? "" : reportQuery.value("Car number").toString();
        QString dateStart = isDuplicateRow ? "" : reportQuery.value("from").toDate().toString("dd.MM.yyyy");
        QString dateFinish = isDuplicateRow ? "" : reportQuery.value("to").toDate().toString("dd.MM.yyyy");
        QString worker = isDuplicateRow ? "" : reportQuery.value("Worker").toString();
        QString position = isDuplicateRow ? "" : reportQuery.value("Position").toString();
        QString workName = isDuplicateRow ? "" : reportQuery.value("Work").toString();
        QString workPrice = isDuplicateRow ? "" : reportQuery.value("Work price").toString();
        QString totalCostStr = isDuplicateRow ? "" : reportQuery.value("Total Cost").toString();

        QString detailName = reportQuery.value("Detail").toString();
        QString detailCost = reportQuery.value("Detail cost").toString();

        if (!countedContractIds.contains(id)) {
            bool ok;
            double cost = reportQuery.value("Total Cost").toDouble(&ok);
            if (ok) {
                totalProfit += cost;
            }
            countedContractIds.insert(id);
        }

        const QString data[] = {
            isDuplicateRow ? "" : id, client, carYear, carNumber, dateStart, dateFinish,
            detailName, detailCost, worker, position, workName, workPrice, totalCostStr
        };

        for (int i = 0; i < numColumns; ++i) {
            Qt::Alignment alignment = (i == 11 || i == 12) ? Qt::AlignRight : Qt::AlignLeft;
            int offsetX = (i == 8) ? 5 : 0;

            painter.drawText(currentX + offsetX, currentY, colWidths[i], rowHeight, alignment | Qt::AlignVCenter, data[i]);
            currentX += colWidths[i];
        }

        currentY += rowHeight;

        previousId = id;

    }

    currentY += 2 * rowHeight;

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(margin, currentY, QString("Загальний дохід за період: %1")
                                           .arg(QLocale::system().toCurrencyString(totalProfit)));

    painter.end();

    QMessageBox::information(this, "Success", QString("Report saved in file:\n%1").arg(filePath));
}


