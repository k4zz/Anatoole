#include "PathsWidget.h"

#include "ui_PathsWidget.h"

#include <QPushButton>
#include <QFileDialog>

PathsWidget::PathsWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::PathsWidget)
{
    ui->setupUi(this);

    connect(ui->btnProtocol, &QPushButton::clicked, this, &PathsWidget::onProtocolButtonClicked);
    connect(ui->btnCollation, &QPushButton::clicked, this, &PathsWidget::onCollationButtonClicked);
}

void PathsWidget::onProtocolButtonClicked()
{
    auto filename = QFileDialog::getOpenFileName(this,
                                                 "Wybierz protokół",
                                                 QDir::homePath(),
                                                 "Excel file (*.xlsx)");
    ui->leProtocol->setText(filename);
}

void PathsWidget::onCollationButtonClicked()
{
    auto filename = QFileDialog::getOpenFileName(this,
                                                 "Wybierz zestawienie",
                                                 QDir::homePath(),
                                                 "Excel file (*.xlsx)");
    ui->leCollation->setText(filename);
}
