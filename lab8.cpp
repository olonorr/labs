#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#define NOMINMAX
#include <windows.h> // Для SetConsoleCP, SetConsoleOutputCP (русский язык)

// 1. Структура "Товар", содержащая все необходимые поля
struct Tovar {
    std::string name;        // наименование товара
    std::string manufacturer; // производитель
    int rubles;              // рубли (целая часть стоимости)
    int kopecks;             // копейки (дробная часть, 0-99)
    int code;                // код товара (уникальный идентификатор)
    int quantity;            // количество на складе
};

// Процедура ввода одного целого числа с проверкой диапазона
int inputInt(const std::string& prompt, int minValue, int maxValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        // Проверка на ошибку ввода (не число)
        if (std::cin.fail()) {
            std::cin.clear(); // сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введите целое число!" << std::endl;
            continue;
        }

        // Проверка диапазона
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

        // Проверка, что строка не пустая и не состоит из пробелов
        if (value.empty() || value.find_first_not_of(' ') == std::string::npos) {
            std::cout << "Ошибка: поле не может быть пустым!" << std::endl;
            continue;
        }
        return value;
    }
}

// Ввод копеек (0-99) с проверкой
int inputKopecks() {
    int kop;
    while (true) {
        kop = inputInt("Введите копейки (0-99): ", 0, 99);
        return kop;
    }
}

// Процедура заполнения динамического массива структур (шаг 3)
void fillArray(Tovar* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "\n--- Ввод данных о товаре №" << i + 1 << " ---" << std::endl;
        
        // Ввод наименования
        arr[i].name = inputString("Наименование: ");
        
        // Ввод производителя
        arr[i].manufacturer = inputString("Производитель: ");
        
        // Ввод рублей
        arr[i].rubles = inputInt("Стоимость (рубли): ", 0, 1000000);
        
        // Ввод копеек
        arr[i].kopecks = inputKopecks();
        
        // Ввод кода товара (целое положительное число)
        arr[i].code = inputInt("Код товара: ", 1, 999999);
        
        // Ввод количества
        arr[i].quantity = inputInt("Количество: ", 0, 100000);
    }
}

// Функция для вывода разделительной линии таблицы
void printLine(int widths[], int columns) {
    std::cout << "+";
    for (int i = 0; i < columns; ++i) {
        std::cout << std::string(widths[i] + 2, '-') << "+";
    }
    std::cout << std::endl;
}

// Процедура вывода таблицы с данными (шаг 4)
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
    
    // Поиск максимальной длины данных в каждом столбце
    for (int i = 0; i < size; ++i) {
        if ((int)arr[i].name.length() > widths[0]) widths[0] = arr[i].name.length();
        if ((int)arr[i].manufacturer.length() > widths[1]) widths[1] = arr[i].manufacturer.length();
        
        // Для стоимости: формат "руб.коп" (например, 123.45)
        std::string costStr = std::to_string(arr[i].rubles) + "." + 
                              (arr[i].kopecks < 10 ? "0" : "") + std::to_string(arr[i].kopecks);
        if ((int)costStr.length() > widths[2]) widths[2] = costStr.length();
        
        // Код и количество - числа, преобразуем в строку для расчёта ширины
        std::string codeStr = std::to_string(arr[i].code);
        std::string qtyStr = std::to_string(arr[i].quantity);
        if ((int)codeStr.length() > widths[3]) widths[3] = codeStr.length();
        if ((int)qtyStr.length() > widths[4]) widths[4] = qtyStr.length();
    }
    
    // Печать шапки таблицы
    printLine(widths, COLUMNS);
    std::cout << "|";
    for (int i = 0; i < COLUMNS; ++i) {
        std::cout << " " << std::left << std::setw(widths[i]) << headers[i] << " |";
    }
    std::cout << std::endl;
    printLine(widths, COLUMNS);
    
    // Печать строк данных
    for (int i = 0; i < size; ++i) {
        std::cout << "| ";
        std::cout << std::left << std::setw(widths[0]) << arr[i].name << " | ";
        std::cout << std::left << std::setw(widths[1]) << arr[i].manufacturer << " | ";
        
        // Форматирование стоимости рубли.копейки
        std::string costStr = std::to_string(arr[i].rubles) + "." + 
                              (arr[i].kopecks < 10 ? "0" : "") + std::to_string(arr[i].kopecks);
        std::cout << std::right << std::setw(widths[2]) << costStr << " | ";
        
        std::cout << std::right << std::setw(widths[3]) << arr[i].code << " | ";
        std::cout << std::right << std::setw(widths[4]) << arr[i].quantity << " |\n";
    }
    printLine(widths, COLUMNS);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    int n;
    std::cout << "Программа для работы со структурой 'Товар'" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    n = inputInt("Введите количество товаров (1-100): ", 1, 100);
    
    // Объявление динамического массива объектов структуры Tovar
    Tovar* tovars = new Tovar[n];
    
    // Заполнение массива с консоли (с проверками)
    fillArray(tovars, n);
    
    // Вывод данных в виде таблицы
    std::cout << "\n\nСписок товаров:\n" << std::endl;
    printTable(tovars, n);
    
    // Освобождение динамической памяти
    delete[] tovars;
    
    std::cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}