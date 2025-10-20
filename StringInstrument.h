#ifndef STRINGINSTRUMENT_H
#define STRINGINSTRUMENT_H

#include "Base.h"

class StringInstrument : public Base
{
    std::string title;
    std::string manufacturer;
    double price;
    int count;
    std::string shortDesc;

public:
    StringInstrument();
    StringInstrument(const std::string &title, const std::string &owner, const std::string &manufacturer,
                     double price, int count, const std::string &desc);
    StringInstrument(const StringInstrument &other);
    ~StringInstrument() override;

    void print(std::ostream &os) const override;
    void editInteractive() override;
    void save(std::ostream &os) const override;
    static StringInstrument *loadFromStream(std::istream &is);

    int typeId() const override { return 2; }
};

#endif
