#include "LogConsoleWidget.h"

#include "ui_LogConsoleWidget.h"

LogConsoleWidget::LogConsoleWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::LogConsoleWidget)
{
    ui->setupUi(this);

    Logger::instance().subscribe(this);

    ui->tbLogConsole->setHorizontalHeaderLabels(QStringList{"Level", "Message"});
    ui->tbLogConsole->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    connect(ui->btnClear, &QPushButton::clicked, this, &LogConsoleWidget::onClearButtonClicked);

    LOG_DEBUG("Log console widget created");
}

void LogConsoleWidget::log(const std::string& _msg, LogLevel _level)
{
    // LEVEL column
    ui->tbLogConsole->insertRow(ui->tbLogConsole->rowCount());
    auto item = new QTableWidgetItem(QString::fromStdString(toString(_level)));
    item->setFlags(Qt::NoItemFlags);
    ui->tbLogConsole->setItem(ui->tbLogConsole->rowCount() - 1,
                              0,
                              item);

    // MSG column
    item = new QTableWidgetItem(QString::fromStdString(_msg));
    item->setFlags(Qt::NoItemFlags);
    ui->tbLogConsole->setItem(ui->tbLogConsole->rowCount() - 1,
                              1,
                              item);
}

void LogConsoleWidget::onClearButtonClicked()
{
    ui->tbLogConsole->setRowCount(0);
}
