#include "StringInstrument.h"
#include <limits>

StringInstrument::StringInstrument()
    : Base(), title("unknown"), manufacturer("unknown"), price(0.0), count(0), shortDesc("none")
{
    std::cout << "[StringInstrument] default constructor\n";
}

StringInstrument::StringInstrument(const std::string &title_, const std::string &owner_, const std::string &manufacturer_,
                                   double price_, int count_, const std::string &desc_)
    : Base(owner_), title(title_), manufacturer(manufacturer_), price(price_), count(count_), shortDesc(desc_)
{
    std::cout << "[StringInstrument] param constructor for " << title << "\n";
}

StringInstrument::StringInstrument(const StringInstrument &other)
    : Base(other), title(other.title), manufacturer(other.manufacturer), price(other.price),
      count(other.count), shortDesc(other.shortDesc)
{
    std::cout << "[StringInstrument] copy constructor\n";
}

StringInstrument::~StringInstrument()
{
    std::cout << "[StringInstrument] destructor for " << title << "\n";
}

void StringInstrument::print(std::ostream &os) const
{
    os << "String | title: " << title << ", manufacturer: " << manufacturer
       << ", price: " << price << ", count: " << count
       << ", owner: " << nameOwner << ", desc: " << shortDesc << "\n";
}

void StringInstrument::editInteractive()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите название (title): ";
    std::getline(std::cin, title);
    std::cout << "Введите ФИО владельца: ";
    std::getline(std::cin, nameOwner);
    std::cout << "Введите производителя: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Введите цену: ";
    std::cin >> price;
    std::cout << "Введите количество в оркестре: ";
    std::cin >> count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите краткое описание: ";
    std::getline(std::cin, shortDesc);
}

void StringInstrument::save(std::ostream &os) const
{
    os << typeId() << "\n";
    os << title << "\n";
    os << nameOwner << "\n";
    os << manufacturer << "\n";
    os << price << "\n";
    os << count << "\n";
    os << shortDesc << "\n";
}

StringInstrument *StringInstrument::loadFromStream(std::istream &is)
{
    StringInstrument *p = new StringInstrument();
    if (!std::getline(is, p->title))
        throw LabException("Error loading String.title");
    if (!std::getline(is, p->nameOwner))
        throw LabException("Error loading String.owner");
    if (!std::getline(is, p->manufacturer))
        throw LabException("Error loading String.manufacturer");
    if (!(is >> p->price))
        throw LabException("Error loading String.price");
    if (!(is >> p->count))
        throw LabException("Error loading String.count");
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(is, p->shortDesc))
        throw LabException("Error loading String.desc");
    return p;
}
