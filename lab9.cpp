#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <algorithm>
#define NOMINMAX
#include <windows.h>


struct Tovar {
    std::string name;        // наименование товара
    std::string manufacturer; // производитель
    int rubles;              // рубли
    int kopecks;             // копейки (0-99)
    int code;                // код товара
    int quantity;            // количество
};


Tovar* tovars = nullptr;
int tovarCount = 0;

int inputInt(const std::string& prompt, int minValue, int maxValue);
std::string inputString(const std::string& prompt);
int inputKopecks();
void inputData();
void printTable(const Tovar* arr, int size);
void printAllData();
double getTotalCost();
void printTotalCost();
void printByNameSorted();
void printByManufacturer();
void printLowQuantity();
void sortByName(Tovar* arr, int size);
void sortByCost(Tovar* arr, int size);
void cleanup();
void showMenu();

// Функция для получения стоимости в рублях (с копейками как дробная часть)
double getCostInRubles(const Tovar& item) {
    return item.rubles + item.kopecks / 100.0;
}

// Ввод целого числа с проверкой
int inputInt(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое число!" << std::endl;
            continue;
        }

        if (value < minValue || value > maxValue) {
            std::cout << "Ошибка: значение должно быть от " << minValue 
                      << " до " << maxValue << "!" << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

// Ввод строки с проверкой на пустоту
std::string inputString(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);

        if (value.empty() || value.find_first_not_of(' ') == std::string::npos) {
            std::cout << "Ошибка: поле не может быть пустым!" << std::endl;
            continue;
        }
        return value;
    }
}

// Ввод копеек
int inputKopecks() {
    return inputInt("Введите копейки (0-99): ", 0, 99);
}

// Ввод данных
void inputData() {
    int n = inputInt("Введите количество товаров (1-100): ", 1, 100);
    
    // Освобождаем старый массив, если он существует
    cleanup();
    
    // Создаём новый динамический массив
    tovars = new Tovar[n];
    tovarCount = n;
    
    // Заполняем массив
    for (int i = 0; i < tovarCount; ++i) {
        std::cout << "\n--- Ввод данных о товаре №" << i + 1 << " ---" << std::endl;
        
        tovars[i].name = inputString("Наименование: ");
        tovars[i].manufacturer = inputString("Производитель: ");
        tovars[i].rubles = inputInt("Стоимость (рубли): ", 0, 1000000);
        tovars[i].kopecks = inputKopecks();
        tovars[i].code = inputInt("Код товара: ", 1, 999999);
        tovars[i].quantity = inputInt("Количество: ", 0, 100000);
    }
    
    std::cout << "\nДанные успешно введены!" << std::endl;
}

// Вывод таблицы (перегрузка для работы с массивом и размером)
void printTable(const Tovar* arr, int size) {
    if (size == 0) {
        std::cout << "Нет данных для отображения." << std::endl;
        return;
    }
    
    const int COLUMNS = 5;
    int widths[COLUMNS];
    std::string headers[COLUMNS] = {"Наименование", "Производитель", "Стоимость (руб)", "Код товара", "Количество"};
    
    // Инициализация ширины заголовками
    for (int i = 0; i < COLUMNS; ++i) {
        widths[i] = headers[i].length();
    }
    
    // Поиск максимальной длины данных
    for (int i = 0; i < size; ++i) {
        if ((int)arr[i].name.length() > widths[0]) widths[0] = arr[i].name.length();
        if ((int)arr[i].manufacturer.length() > widths[1]) widths[1] = arr[i].manufacturer.length();
        
        std::string costStr = std::to_string(arr[i].rubles) + "." + 
                              (arr[i].kopecks < 10 ? "0" : "") + std::to_string(arr[i].kopecks);
        if ((int)costStr.length() > widths[2]) widths[2] = costStr.length();
        
        std::string codeStr = std::to_string(arr[i].code);
        std::string qtyStr = std::to_string(arr[i].quantity);
        if ((int)codeStr.length() > widths[3]) widths[3] = codeStr.length();
        if ((int)qtyStr.length() > widths[4]) widths[4] = qtyStr.length();
    }
    
    // Вывод таблицы
    auto printLine = [&]() {
        std::cout << "+";
        for (int i = 0; i < COLUMNS; ++i) {
            std::cout << std::string(widths[i] + 2, '-') << "+";
        }
        std::cout << std::endl;
    };
    
    printLine();
    std::cout << "|";
    for (int i = 0; i < COLUMNS; ++i) {
        std::cout << " " << std::left << std::setw(widths[i]) << headers[i] << " |";
    }
    std::cout << std::endl;
    printLine();
    
    for (int i = 0; i < size; ++i) {
        std::cout << "| ";
        std::cout << std::left << std::setw(widths[0]) << arr[i].name << " | ";
        std::cout << std::left << std::setw(widths[1]) << arr[i].manufacturer << " | ";
        
        std::string costStr = std::to_string(arr[i].rubles) + "." + 
                              (arr[i].kopecks < 10 ? "0" : "") + std::to_string(arr[i].kopecks);
        std::cout << std::right << std::setw(widths[2]) << costStr << " | ";
        std::cout << std::right << std::setw(widths[3]) << arr[i].code << " | ";
        std::cout << std::right << std::setw(widths[4]) << arr[i].quantity << " |\n";
    }
    printLine();
}

// Вывод всей информации
void printAllData() {
    if (tovarCount == 0) {
        std::cout << "\nОшибка: Сначала введите данные (пункт 1 меню)!" << std::endl;
        return;
    }
    std::cout << "\n=== ВСЕ ТОВАРЫ ===" << std::endl;
    printTable(tovars, tovarCount);
}

// Расчёт общей стоимости всех товаров (количество * цена)
double getTotalCost() {
    double total = 0.0;
    for (int i = 0; i < tovarCount; ++i) {
        total += (tovars[i].rubles + tovars[i].kopecks / 100.0) * tovars[i].quantity;
    }
    return total;
}

// Общая стоимость товаров
void printTotalCost() {
    if (tovarCount == 0) {
        std::cout << "\nОшибка: Сначала введите данные (пункт 1 меню)!" << std::endl;
        return;
    }
    double total = getTotalCost();
    int rub = (int)total;
    int kop = (int)((total - rub) * 100 + 0.5);
    std::cout << "\n=== ОБЩАЯ СТОИМОСТЬ ВСЕХ ТОВАРОВ ===" << std::endl;
    std::cout << "Общая стоимость: " << rub << " руб. " << kop << " коп." << std::endl;
}

// Сортировка по стоимости (возрастание) - эффективная быстрая сортировка через std::sort
void sortByCost(Tovar* arr, int size) {
    std::sort(arr, arr + size, [](const Tovar& a, const Tovar& b) {
        double costA = a.rubles + a.kopecks / 100.0;
        double costB = b.rubles + b.kopecks / 100.0;
        return costA < costB;
    });
}

// Сортировка по наименованию (для алфавитного порядка)
void sortByName(Tovar* arr, int size) {
    std::sort(arr, arr + size, [](const Tovar& a, const Tovar& b) {
        return a.name < b.name;
    });
}

// Пункт меню 4: Перечень товаров определённого наименования, отсортированный по стоимости
void printByNameSorted() {
    if (tovarCount == 0) {
        std::cout << "\nОшибка: Сначала введите данные (пункт 1 меню)!" << std::endl;
        return;
    }
    
    std::string searchName = inputString("Введите наименование товара для поиска: ");
    
    // Создаём временный массив для подходящих товаров
    Tovar* temp = new Tovar[tovarCount];
    int tempCount = 0;
    
    for (int i = 0; i < tovarCount; ++i) {
        if (tovars[i].name == searchName) {
            temp[tempCount++] = tovars[i];
        }
    }
    
    if (tempCount == 0) {
        std::cout << "\nТовары с наименованием \"" << searchName << "\" не найдены!" << std::endl;
    } else {
        // Сортируем по возрастанию стоимости
        sortByCost(temp, tempCount);
        
        std::cout << "\n=== ТОВАРЫ \"" << searchName << "\" (ОТСОРТИРОВАНЫ ПО СТОИМОСТИ) ===" << std::endl;
        printTable(temp, tempCount);
        
        // Выводим также стоимости отдельно для наглядности
        std::cout << "\nСтоимости товаров:" << std::endl;
        for (int i = 0; i < tempCount; ++i) {
            std::cout << "  " << i + 1 << ". " << temp[i].name 
                      << " - " << temp[i].rubles << " руб. " << temp[i].kopecks << " коп." << std::endl;
        }
    }
    
    delete[] temp;
}

// Пункт меню 5: Перечень товаров введённого производителя
void printByManufacturer() {
    if (tovarCount == 0) {
        std::cout << "\nОшибка: Сначала введите данные (пункт 1 меню)!" << std::endl;
        return;
    }
    
    std::string searchManufacturer = inputString("Введите наименование производителя: ");
    
    // Создаём временный массив
    Tovar* temp = new Tovar[tovarCount];
    int tempCount = 0;
    
    for (int i = 0; i < tovarCount; ++i) {
        if (tovars[i].manufacturer == searchManufacturer) {
            temp[tempCount++] = tovars[i];
        }
    }
    
    if (tempCount == 0) {
        std::cout << "\nТовары производителя \"" << searchManufacturer << "\" не найдены!" << std::endl;
    } else {
        std::cout << "\n=== ТОВАРЫ ПРОИЗВОДИТЕЛЯ \"" << searchManufacturer << "\" ===" << std::endl;
        printTable(temp, tempCount);
    }
    
    delete[] temp;
}

// Пункт меню 6: Перечень товаров с количеством менее пяти
void printLowQuantity() {
    if (tovarCount == 0) {
        std::cout << "\nОшибка: Сначала введите данные (пункт 1 меню)!" << std::endl;
        return;
    }
    
    // Создаём временный массив
    Tovar* temp = new Tovar[tovarCount];
    int tempCount = 0;
    
    for (int i = 0; i < tovarCount; ++i) {
        if (tovars[i].quantity < 5) {
            temp[tempCount++] = tovars[i];
        }
    }
    
    if (tempCount == 0) {
        std::cout << "\nТовары с количеством менее 5 не найдены!" << std::endl;
    } else {
        std::cout << "\n=== ТОВАРЫ С КОЛИЧЕСТВОМ МЕНЕЕ 5 ===" << std::endl;
        printTable(temp, tempCount);
        
        // Дополнительная информация
        std::cout << "\nВсего таких товаров: " << tempCount << std::endl;
        std::cout << "Рекомендуется пополнить запасы!" << std::endl;
    }
    
    delete[] temp;
}

// Освобождение памяти
void cleanup() {
    if (tovars != nullptr) {
        delete[] tovars;
        tovars = nullptr;
        tovarCount = 0;
    }
}

// Вывод меню
void showMenu() {
    std::cout << "\n===========================================" << std::endl;
    std::cout << "            ГЛАВНОЕ МЕНЮ                  " << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "1. Ввод данных о товарах" << std::endl;
    std::cout << "2. Вывод всей информации" << std::endl;
    std::cout << "3. Общая стоимость всех товаров" << std::endl;
    std::cout << "4. Товары определённого наименования (по возрастанию стоимости)" << std::endl;
    std::cout << "5. Товары определённого производителя" << std::endl;
    std::cout << "6. Товары с количеством менее 5" << std::endl;
    std::cout << "7. Выход из программы" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << "Ваш выбор: ";
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    int choice;
    
    std::cout << "===========================================" << std::endl;
    std::cout << "   ПРОГРАММА УЧЁТА ТОВАРОВ НА СКЛАДЕ     " << std::endl;
    std::cout << "===========================================" << std::endl;
    
    // Цикл меню
    do {
        showMenu();
        std::cin >> choice;
        
        // Проверка на некорректный ввод номера пункта
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nОшибка: Введите число от 1 до 7!" << std::endl;
            continue;
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Обработка выбора
        switch (choice) {
            case 1:
                inputData();
                break;
            case 2:
                printAllData();
                break;
            case 3:
                printTotalCost();
                break;
            case 4:
                printByNameSorted();
                break;
            case 5:
                printByManufacturer();
                break;
            case 6:
                printLowQuantity();
                break;
            case 7:
                std::cout << "\nЗавершение работы программы..." << std::endl;
                break;
            default:
                std::cout << "\nОшибка: Неверный пункт меню! Введите число от 1 до 7." << std::endl;
                break;
        }
        
    } while (choice != 7);
    
    cleanup();
    
    return 0;
}