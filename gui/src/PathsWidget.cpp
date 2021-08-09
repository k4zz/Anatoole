#include "PathsWidget.h"

#include "ui_PathsWidget.h"

#include "Logger.h"

#include <QPushButton>
#include <QFileDialog>
#include <QLineEdit>

PathsWidget::PathsWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::PathsWidget)
        , valid(false)
{
    ui->setupUi(this);
    swapLineEditColors(ui->leProtocol, false);
    swapLineEditColors(ui->leCollation, false);

    connect(ui->btnProtocol, &QPushButton::clicked, this, &PathsWidget::onProtocolButtonClicked);
    connect(ui->btnCollation, &QPushButton::clicked, this, &PathsWidget::onCollationButtonClicked);
    connect(ui->leProtocol, &QLineEdit::textChanged, this, &PathsWidget::onLineEditChanged);
    connect(ui->leCollation, &QLineEdit::textChanged, this, &PathsWidget::onLineEditChanged);

    LOG_DEBUG("Paths widget created");
}

void PathsWidget::onProtocolButtonClicked()
{
    auto filename = QFileDialog::getOpenFileName(this,
                                                 "Wybierz protokół",
                                                 QDir::homePath(),
                                                 "Excel file (*.xlsx)");
    if (filename.isEmpty())
        LOG_INFO("No protocol path was selected");
    else
        LOG_INFO("Selected protocol path: " + filename.toStdString());
    ui->leProtocol->setText(filename);
}

void PathsWidget::onCollationButtonClicked()
{
    auto filename = QFileDialog::getOpenFileName(this,
                                                 "Wybierz zestawienie",
                                                 QDir::homePath(),
                                                 "Excel file (*.xlsx)");
    if (filename.isEmpty())
        LOG_INFO("No collation path was selected");
    else
        LOG_INFO("Selected collation path: " + filename.toStdString());
    ui->leCollation->setText(filename);
}

void PathsWidget::onLineEditChanged(const QString& _path)
{
    swapLineEditColors(qobject_cast<QLineEdit*>(sender()), checkPathValid(_path));
    qobject_cast<QLineEdit*>(sender())->setToolTip(_path);
}

bool PathsWidget::checkPathValid(const QString& _path)
{
    auto valid = true;
    valid = _path.endsWith(".xlsx");

    return valid;
}

void PathsWidget::swapLineEditColors(QLineEdit* _lineEdit, bool _valid)
{
    if(_valid)
        _lineEdit->setStyleSheet("QLineEdit {background-color: #FFFFFF;}");
    else
        _lineEdit->setStyleSheet("QLineEdit {background-color: #FA756E;}");
}

std::string PathsWidget::getProtocolPath()
{
    return ui->leProtocol->text().toStdString();
}

std::string PathsWidget::getCollationPath()
{
    return ui->leCollation->text().toStdString();
}
