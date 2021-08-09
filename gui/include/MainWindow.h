#pragma once

#include <QMainWindow>
#include <Controller.h>
#include "BaseComponent.h"

namespace Ui
{
    class MainWindow;
}

class PathsWidget;
class SettingsWidget;
class Settings;

class MainWindow : public QMainWindow, public BaseComponent
{
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void updateSettings();

private slots:
    void onAnalyzeButtonClicked();

private:
    Ui::MainWindow* ui;
    PathsWidget* pathsWidget;

    SettingsWidget* settingsWidget;
    Settings* settings;
};