#include <set>

class FileBase
{
public:
    FileBase();
    void setKey(const std::string& _key) { key = _key; }
    const std::string& getKey() const { return key; }

    void addValue(const std::string& _value) { values.insert(_value); }
    bool hasValue(const std::string& _value) { return values.count(_value); }

    void setFromWhichRow(int _row) { rowFromFile = _row; }
    int getFromWhichRow() const { return rowFromFile; }

private:
    std::string key;
    std::set<std::string> values;
    int rowFromFile;
};