#include "LogConsoleWidget.h"

#include "ui_LogConsoleWidget.h"

LogConsoleWidget::LogConsoleWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::LogConsoleWidget)
{
    ui->setupUi(this);

    Logger::instance().subscribe(this);

    ui->tbLogConsole->setHorizontalHeaderLabels(QStringList{"Level", "Place", "Message"});
    ui->tbLogConsole->setColumnWidth(0,80);
    ui->tbLogConsole->setColumnWidth(1,150);
    ui->tbLogConsole->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    connect(ui->btnClear, &QPushButton::clicked, this, &LogConsoleWidget::onClearButtonClicked);
}

void LogConsoleWidget::log(const std::string& _msg, LogLevel _level, const std::string& _fileName, int _line)
{
    if(_level < LogLevel::INFO && !ui->cbDebugMode->checkState())
        return;

    // LEVEL column
    ui->tbLogConsole->insertRow(ui->tbLogConsole->rowCount());
    auto item = new QTableWidgetItem(QString::fromStdString(toString(_level)));
    item->setFlags(Qt::NoItemFlags);
    ui->tbLogConsole->setItem(ui->tbLogConsole->rowCount() - 1,
                              0,
                              item);
    switch (_level) {
        case LogLevel::WARNING:
            item->setBackground(QColor::fromRgb(255,255,0, 100));
            break;
        case LogLevel::ERROR:
            item->setBackground(QColor::fromRgb(255,0,0, 100));
            break;
        default:
            break;
    }

    // PLACE column
    item = new QTableWidgetItem(QString::fromStdString(_fileName + ":" + std::to_string(_line)));
    item->setFlags(Qt::NoItemFlags);
    ui->tbLogConsole->setItem(ui->tbLogConsole->rowCount() - 1,
                              1,
                              item);

    // MSG column
    item = new QTableWidgetItem(QString::fromStdString(_msg));
    item->setFlags(Qt::NoItemFlags);
    ui->tbLogConsole->setItem(ui->tbLogConsole->rowCount() - 1,
                              2,
                              item);
}

void LogConsoleWidget::onClearButtonClicked()
{
    ui->tbLogConsole->setRowCount(0);
}
