#pragma once

#include <QWidget>

namespace Ui
{
    class PathsWidget;
}

class PathsWidget : public QWidget
{
Q_OBJECT

public:
    explicit PathsWidget(QWidget* _parent = nullptr);

private:
    Ui::PathsWidget* ui;

private slots:
    void onProtocolButtonClicked();
    void onCollationButtonClicked();
};