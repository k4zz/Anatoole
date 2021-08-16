#include "SettingsWidget.h"

#include "ui_SettingsWidget.h"

#include <QValidator>

#include "Logger.h"

namespace
{
    int convertStringToColumnIterator(const std::string& _str)
    {
        int column = 0;
        for (char i : _str) {
            column = column * 26 + i - 64;
        }
        return column - 1;
    }
}

class Validator
        : public QValidator
{
public:
    QValidator::State validate(QString& input, int& pos) const override
    {
        fixup(input);
        if (input.isEmpty())
            return State::Acceptable;
        if(not input.at(pos-1).isDigit())
        {
            return State::Acceptable;
        }
        return State::Invalid;
    }

    void fixup(QString& input) const override
    {
        input = input.toUpper();
    }
};

SettingsWidget::SettingsWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
    ui->leProtocolNum->setValidator(new Validator());
    ui->leProtocolNum->insert("A");
    ui->leProtocolName->setValidator(new Validator());
    ui->leProtocolName->insert("C");
    ui->leCollationNum->setValidator(new Validator());
    ui->leCollationNum->insert("C");
    ui->leCollationName->setValidator(new Validator());
    ui->leCollationName->insert("B");
}

Settings SettingsWidget::getSettings() const
{
    return Settings{convertStringToColumnIterator(ui->leProtocolNum->text().toStdString()),
                    convertStringToColumnIterator(ui->leProtocolName->text().toStdString()),
                    convertStringToColumnIterator(ui->leCollationName->text().toStdString()),
                    convertStringToColumnIterator(ui->leCollationNum->text().toStdString())};
}
