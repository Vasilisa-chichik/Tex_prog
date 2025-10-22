#include "Percussion.h"
#include <limits>

Percussion::Percussion() : Base(), kind("unknown"), title("unknown"), price(0.0), count(0)
{
    std::cout << "[Percussion] default constructor\n";
}

Percussion::Percussion(const std::string &kind_, const std::string &title_, double price_, int count_, const std::string &owner)
    : Base(owner), kind(kind_), title(title_), price(price_), count(count_)
{
    std::cout << "[Percussion] param constructor for " << title << "\n";
}

Percussion::Percussion(const Percussion &other)
    : Base(other), kind(other.kind), title(other.title), price(other.price), count(other.count)
{
    std::cout << "[Percussion] copy constructor\n";
}

Percussion::~Percussion()
{
    std::cout << "[Percussion] destructor for " << title << "\n";
}

void Percussion::print(std::ostream &os) const
{
    os << "Тип – " << kind << ", Название – " << title
       << ", Цена – " << price << ", Количество – " << count
       << ", Владелец –" << nameOwner << "\n";
}

void Percussion::editInteractive()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите тип (kind): ";
    std::getline(std::cin, kind);
    std::cout << "Введите название (title): ";
    std::getline(std::cin, title);
    std::cout << "Введите цену (price): ";
    std::cin >> price;
    std::cout << "Введите количество единиц в оркестре (count): ";
    std::cin >> count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите ФИО владельца: ";
    std::getline(std::cin, nameOwner);
}

void Percussion::save(std::ostream &os) const
{
    os << typeId() << "\n";
    os << kind << "\n"
       << title << "\n";
    os << price << "\n"
       << count << "\n";
    os << nameOwner << "\n";
}

Percussion *Percussion::loadFromStream(std::istream &is)
{
    Percussion *p = new Percussion();
    if (!std::getline(is, p->kind))
        throw LabException("Error loading Percussion.kind");
    if (!std::getline(is, p->title))
        throw LabException("Error loading Percussion.title");
    if (!(is >> p->price))
        throw LabException("Error loading Percussion.price");
    if (!(is >> p->count))
        throw LabException("Error loading Percussion.count");
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(is, p->nameOwner))
        throw LabException("Error loading Percussion.owner");
    return p;
}
