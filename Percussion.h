#ifndef PERCUSSION_H
#define PERCUSSION_H

#include "Base.h"

class Percussion : public Base
{
    std::string kind;
    std::string title;
    double price;
    int count;

public:
    Percussion();
    Percussion(const std::string &kind, const std::string &title, double price, int count, const std::string &owner);
    Percussion(const Percussion &other);
    ~Percussion() override;

    void print(std::ostream &os) const override;
    void editInteractive() override;
    void save(std::ostream &os) const override;
    static Percussion *loadFromStream(std::istream &is);

    int typeId() const override { return 1; }

    void setKind(const std::string &k) { kind = k; }
    std::string getKind() const { return kind; }
};

#endif
