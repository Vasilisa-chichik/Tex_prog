#ifndef WIND_H
#define WIND_H

#include "Base.h"

class Wind : public Base
{
    std::string title;
    std::string manufacturer;
    double price;
    int count;
    std::string defects;

public:
    Wind();
    Wind(const std::string &title, const std::string &manufacturer, double price, const std::string &owner, int count, const std::string &defects);
    Wind(const Wind &other);
    ~Wind() override;

    void print(std::ostream &os) const override;
    void editInteractive() override;
    void save(std::ostream &os) const override;
    static Wind *loadFromStream(std::istream &is);

    int typeId() const override { return 3; }
};

#endif
