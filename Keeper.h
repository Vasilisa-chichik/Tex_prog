#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <string>

class Keeper
{
    Base **items;
    int capacity;
    int size_;
    void resize(int newCap);

public:
    Keeper();
    ~Keeper();

    void add(Base *b);
    void removeAt(int index);
    Base *getAt(int index) const;
    int size() const { return size_; }

    void listAll(std::ostream &os) const;

    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);

    void clearAll();
};

#endif
