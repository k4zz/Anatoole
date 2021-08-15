#include "SettingsWidget.h"

#include "ui_SettingsWidget.h"

#include <QValidator>

#include "Logger.h"

namespace
{
    int convertStringToColumn(const std::string& _str)
    {
        int column = 0;
        for(auto ch : _str)
        {
            column += ch - 'A';
        }
        return column;
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
    ui->leProtocolName->setValidator(new Validator());
    ui->leCollationNum->setValidator(new Validator());
    ui->leCollationName->setValidator(new Validator());
}

Settings SettingsWidget::getSettings() const
{
    return Settings{convertStringToColumn(ui->leProtocolNum->text().toStdString()),
                    convertStringToColumn(ui->leProtocolName->text().toStdString()),
                    convertStringToColumn(ui->leCollationName->text().toStdString()),
                    convertStringToColumn(ui->leCollationNum->text().toStdString())};
}
