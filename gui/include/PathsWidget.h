#pragma once

#include <QWidget>

class QLineEdit;

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
    void onLineEditChanged(const QString& _path);
    static void swapLineEditColors(QLineEdit* _lineEdit, bool _valid);
    static bool checkPathValid(const QString& _path) ;
};