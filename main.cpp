#include "Keeper.h"
#include "Percussion.h"
#include "StringInstrument.h"
#include "Wind.h"

void showMenu()
{
    std::cout << "\n=== Оркестр: меню ===\n";
    std::cout << "1. Добавить ударный инструмент\n";
    std::cout << "2. Добавить струнный инструмент\n";
    std::cout << "3. Добавить духовой инструмент\n";
    std::cout << "4. Удалить по индексу\n";
    std::cout << "5. Показать все\n";
    std::cout << "6. Редактировать по индексу\n";
    std::cout << "7. Сохранить в файл\n";
    std::cout << "8. Загрузить из файла\n";
    std::cout << "9. Выход\n";
    std::cout << "Выберите опцию: ";
}

int main()
{
    Keeper keeper;
    bool running = true;
    while (running)
    {
        try
        {
            showMenu();
            int opt;
            if (!(std::cin >> opt))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (opt == 1)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string kind, title, owner;
                double price;
                int count;
                std::cout << "Тип (вид) ударного: ";
                std::getline(std::cin, kind);
                std::cout << "Название: ";
                std::getline(std::cin, title);
                std::cout << "Цена: ";
                std::cin >> price;
                std::cout << "Количество: ";
                std::cin >> count;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ФИО владельца: ";
                std::getline(std::cin, owner);
                Percussion *p = new Percussion(kind, title, price, count, owner);
                keeper.add(p);
            }
            else if (opt == 2)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string title, owner, manufacturer, desc;
                double price;
                int count;
                std::cout << "Название: ";
                std::getline(std::cin, title);
                std::cout << "ФИО владельца: ";
                std::getline(std::cin, owner);
                std::cout << "Производитель: ";
                std::getline(std::cin, manufacturer);
                std::cout << "Цена: ";
                std::cin >> price;
                std::cout << "Количество: ";
                std::cin >> count;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Краткое описание: ";
                std::getline(std::cin, desc);
                StringInstrument *s = new StringInstrument(title, owner, manufacturer, price, count, desc);
                keeper.add(s);
            }
            else if (opt == 3)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string title, manufacturer, owner, defects;
                double price;
                int count;
                std::cout << "Название: ";
                std::getline(std::cin, title);
                std::cout << "Производитель: ";
                std::getline(std::cin, manufacturer);
                std::cout << "Цена: ";
                std::cin >> price;
                std::cout << "ФИО владельца: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, owner);
                std::cout << "Количество: ";
                std::cin >> count;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Дефекты (текст): ";
                std::getline(std::cin, defects);
                Wind *w = new Wind(title, manufacturer, price, owner, count, defects);
                keeper.add(w);
            }
            else if (opt == 4)
            {
                std::cout << "Введите индекс для удаления: ";
                int idx;
                std::cin >> idx;
                keeper.removeAt(idx);
            }
            else if (opt == 5)
            {
                keeper.listAll(std::cout);
            }
            else if (opt == 6)
            {
                std::cout << "Введите индекс для редактирования: ";
                int idx;
                std::cin >> idx;
                Base *b = keeper.getAt(idx);
                b->editInteractive();
            }
            else if (opt == 7)
            {
                std::cout << "Введите имя файла для сохранения: ";
                std::string fname;
                std::cin >> fname;
                keeper.saveToFile(fname);
            }
            else if (opt == 8)
            {
                std::cout << "Введите имя файла для загрузки: ";
                std::string fname;
                std::cin >> fname;
                keeper.loadFromFile(fname);
            }
            else if (opt == 9)
            {
                running = false;
            }
            else
            {
                std::cout << "Неизвестная опция\n";
            }
        }
        catch (const LabException &e)
        {
            std::cout << "LabException: " << e.what() << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "std::exception: " << e.what() << "\n";
        }
    }

    std::cout << "Выход из программы.\n";
    return 0;
}
