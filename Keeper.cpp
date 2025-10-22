#include "Keeper.h"
#include "Percussion.h"
#include "StringInstrument.h"
#include "Wind.h"
#include <iostream>
#include <fstream>
#include <limits>

Keeper::Keeper() : items(nullptr), capacity(0), size_(0)
{
    capacity = 4;
    items = new Base *[capacity];
    for (int i = 0; i < capacity; ++i)
        items[i] = nullptr;
    std::cout << "[Keeper] created with capacity " << capacity << "\n";
}

Keeper::~Keeper()
{
    clearAll();
    delete[] items;
    std::cout << "[Keeper] destroyed\n";
}

void Keeper::resize(int newCap)
{
    Base **newArr = new Base *[newCap];
    for (int i = 0; i < newCap; ++i)
        newArr[i] = nullptr;
    for (int i = 0; i < size_; ++i)
        newArr[i] = items[i];
    delete[] items;
    items = newArr;
    capacity = newCap;
    std::cout << "[Keeper] resized to " << capacity << "\n";
}

void Keeper::add(Base *b)
{
    if (!b)
        throw LabException("Null pointer passed to Keeper::add");
    if (size_ >= capacity)
        resize(capacity * 2);
    items[size_++] = b;
    std::cout << "[Keeper] added object, new size: " << size_ << "\n";
}

void Keeper::removeAt(int index)
{
    if (index < 0 || index >= size_)
        throw LabException("Index out of range in removeAt");
    delete items[index];
    for (int i = index; i < size_ - 1; ++i)
        items[i] = items[i + 1];
    items[size_ - 1] = nullptr;
    --size_;
    std::cout << "[Keeper] removed index " << index << ", new size: " << size_ << "\n";
    if (size_ > 0 && size_ <= capacity / 4)
        resize(std::max(4, capacity / 2));
}

Base *Keeper::getAt(int index) const
{
    if (index < 0 || index >= size_)
        throw LabException("Index out of range in getAt");
    return items[index];
}

void Keeper::listAll(std::ostream &os) const
{
    os << "Keeper contents (" << size_ << "):\n";
    for (int i = 0; i < size_; ++i)
    {
        os << "[" << i << "] ";
        items[i]->print(os);
    }
}

void Keeper::saveToFile(const std::string &filename) const
{
    std::ofstream ofs(filename.c_str());
    if (!ofs)
        throw LabException("Cannot open file for writing: " + filename);
    ofs << size_ << "\n";
    for (int i = 0; i < size_; ++i)
    {
        items[i]->save(ofs);
    }
    ofs.close();
    std::cout << "[Keeper] saved to " << filename << "\n";
}

void Keeper::clearAll()
{
    for (int i = 0; i < size_; ++i)
    {
        delete items[i];
        items[i] = nullptr;
    }
    size_ = 0;
}

void Keeper::loadFromFile(const std::string &filename)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs)
        throw LabException("Cannot open file for reading: " + filename);
    clearAll();
    int count = 0;
    ifs >> count;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < count; ++i)
    {
        int tid = 0;
        ifs >> tid;
        ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Base *obj = nullptr;
        if (tid == 1)
        {
            obj = Percussion::loadFromStream(ifs);
        }
        else if (tid == 2)
        {
            obj = StringInstrument::loadFromStream(ifs);
        }
        else if (tid == 3)
        {
            obj = Wind::loadFromStream(ifs);
        }
        else
        {
            throw LabException("Unknown type id in file: " + std::to_string(tid));
        }
        add(obj);
    }
    ifs.close();
    std::cout << "[Keeper] loaded from " << filename << "\n";
}
