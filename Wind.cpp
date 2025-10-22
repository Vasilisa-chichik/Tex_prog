#include "Wind.h"
#include <limits>

Wind::Wind() : Base(), title("unknown"), manufacturer("unknown"), price(0.0), count(0), defects("none")
{
    std::cout << "[Wind] default constructor\n";
}

Wind::Wind(const std::string &title_, const std::string &manufacturer_, double price_, const std::string &owner_, int count_, const std::string &defects_)
    : Base(owner_), title(title_), manufacturer(manufacturer_), price(price_), count(count_), defects(defects_)
{
    std::cout << "[Wind] param constructor for " << title << "\n";
}

Wind::Wind(const Wind &other)
    : Base(other), title(other.title), manufacturer(other.manufacturer), price(other.price), count(other.count), defects(other.defects)
{
    std::cout << "[Wind] copy constructor\n";
}

Wind::~Wind()
{
    std::cout << "[Wind] destructor for " << title << "\n";
}

void Wind::print(std::ostream &os) const
{
    os << "Wind | title: " << title << ", manufacturer: " << manufacturer
       << ", price: " << price << ", count: " << count
       << ", owner: " << nameOwner << ", defects: " << defects << "\n";
}

void Wind::editInteractive()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите название (title): ";
    std::getline(std::cin, title);
    std::cout << "Введите производителя: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Введите цену: ";
    std::cin >> price;
    std::cout << "Введите ФИО владельца: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nameOwner);
    std::cout << "Введите количество: ";
    std::cin >> count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Опишите дефекты (text): ";
    std::getline(std::cin, defects);
}

void Wind::save(std::ostream &os) const
{
    os << typeId() << "\n";
    os << title << "\n";
    os << manufacturer << "\n";
    os << price << "\n";
    os << nameOwner << "\n";
    os << count << "\n";
    os << defects << "\n";
}

Wind *Wind::loadFromStream(std::istream &is)
{
    Wind *p = new Wind();
    if (!std::getline(is, p->title))
        throw LabException("Error loading Wind.title");
    if (!std::getline(is, p->manufacturer))
        throw LabException("Error loading Wind.manufacturer");
    if (!(is >> p->price))
        throw LabException("Error loading Wind.price");
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(is, p->nameOwner))
        throw LabException("Error loading Wind.owner");
    if (!(is >> p->count))
        throw LabException("Error loading Wind.count");
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(is, p->defects))
        throw LabException("Error loading Wind.defects");
    return p;
}
