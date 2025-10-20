#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <exception>

class LabException : public std::exception
{
    std::string msg;

public:
    LabException(const std::string &m) : msg(m) {}
    const char *what() const noexcept override { return msg.c_str(); }
};

class Base
{
protected:
    std::string nameOwner;

public:
    Base() : nameOwner("Unknown")
    {
        std::cout << "[Base] default constructor called\n";
    }
    Base(const std::string &owner) : nameOwner(owner)
    {
        std::cout << "[Base] param constructor called for owner: " << owner << "\n";
    }
    Base(const Base &other) : nameOwner(other.nameOwner)
    {
        std::cout << "[Base] copy constructor called for owner: " << nameOwner << "\n";
    }
    virtual ~Base()
    {
        std::cout << "[Base] destructor called for owner: " << nameOwner << "\n";
    }

    void setOwner(const std::string &o) { nameOwner = o; }
    std::string getOwner() const { return nameOwner; }

    virtual void print(std::ostream &os) const = 0;
    virtual void editInteractive();
    virtual void save(std::ostream &os) const = 0;
    virtual int typeId() const = 0;
};

#endif
