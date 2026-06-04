#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Абстрактный базовый класс Мебель
class Furniture {
protected:
    string name;        // наименование
    double cost;        // стоимость
    string manufacturer; // производитель

public:
    // Конструктор
    Furniture(const string& n, double c, const string& m) 
        : name(n), cost(c), manufacturer(m) {}
    
    // Виртуальный деструктор
    virtual ~Furniture() {}
    
    // Чистая виртуальная функция
    virtual void displayInfo() const = 0;
    
    // Виртуальная функция для вывода данных
    virtual void print() const {
        cout << "Наименование: " << name << endl;
        cout << "Стоимость: " << cost << " руб." << endl;
        cout << "Производитель: " << manufacturer << endl;
    }
    
    // Геттеры
    string getName() const { return name; }
    double getCost() const { return cost; }
    string getManufacturer() const { return manufacturer; }
    
    // Сеттеры
    void setCost(double newCost) { cost = newCost; }
};

// Производный класс Стол
class Table : public Furniture {
private:
    string color;       // цвет
    double width;       // ширина
    double length;      // длина
    string shape;       // вид (круглый, квадратный, прямоугольный)

public:
    // Конструктор
    Table(const string& n = "", double c = 0, const string& m = "", 
          const string& col = "", double w = 0, double l = 0, const string& sh = "")
        : Furniture(n, c, m), color(col), width(w), length(l), shape(sh) {}
    
    // Конструктор копирования
    Table(const Table& other) 
        : Furniture(other.getName(), other.getCost(), other.getManufacturer()),
          color(other.color), width(other.width), length(other.length), shape(other.shape) {}
    
    // Переопределение виртуальной функции вывода
    void print() const override {
        Furniture::print();
        cout << "Цвет: " << color << endl;
        cout << "Размеры (ширина x длина): " << width << " x " << length << " см" << endl;
        cout << "Вид: " << shape << endl;
    }
    
    // Реализация чистой виртуальной функции
    void displayInfo() const override {
        cout << "\n=== Информация о столе ===" << endl;
        print();
        cout << "===========================" << endl;
    }
    
    // Дополнительные методы
    string getShape() const { return shape; }
    string getColor() const { return color; }
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getArea() const { return width * length; }
    
    // Метод для изменения цены
    void setCost(double newCost) { cost = newCost; }
    
    // Оператор присваивания
    Table& operator=(const Table& other) {
        if (this != &other) {
            Furniture::operator=(other);
            color = other.color;
            width = other.width;
            length = other.length;
            shape = other.shape;
        }
        return *this;
    }
    
    // Оператор сравнения для сортировки по стоимости
    bool operator<(const Table& other) const {
        return cost < other.cost;
    }
    
    // Оператор сравнения для сортировки по наименованию
    bool operator<(const string& otherName) const {
        return name < otherName;
    }
};

// Функция для отображения всех столов в контейнере
void displayAllTables(const vector<Table>& tables, const string& title = "Список столов") {
    cout << "\n=== " << title << " ===" << endl;
    if (tables.empty()) {
        cout << "Контейнер пуст!" << endl;
        return;
    }
    
    for (size_t i = 0; i < tables.size(); i++) {
        cout << "\n[" << i + 1 << "] ";
        tables[i].displayInfo();
    }
    cout << "\nВсего столов: " << tables.size() << endl;
    cout << "===========================" << endl;
}

// Функция для создания тестовых столов
Table createTestTable(int id) {
    string names[] = {"Обеденный стол", "Журнальный столик", "Письменный стол", 
                      "Компьютерный стол", "Кофейный столик", "Кухонный стол", 
                      "Барный стол", "Раскладной стол"};
    string colors[] = {"Дуб", "Белый", "Черный", "Орех", "Красный", "Серый", "Бежевый"};
    string shapes[] = {"круглый", "квадратный", "прямоугольный"};
    string manufacturers[] = {"IKEA", "Hoff", "Леруа Мерлен", "Шатура", "Дятьково", "Mebel City"};
    
    int nameIdx = id % 8;
    int colorIdx = id % 7;
    int shapeIdx = id % 3;
    int manIdx = id % 6;
    
    double cost = 5000 + (rand() % 30000);
    double width = 50 + (rand() % 100);
    double length = 50 + (rand() % 150);
    
    return Table(names[nameIdx], cost, manufacturers[manIdx], 
                 colors[colorIdx], width, length, shapes[shapeIdx]);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    
    vector<Table> tables; // Контейнерный класс
    
    cout << "=== Демонстрация работы с контейнером vector<Table> ===" << endl;
    
    // 1. Добавление элементов различными способами
    
    // Добавление в конец (push_back)
    cout << "\n--- 1. Добавление элементов в КОНЕЦ контейнера ---" << endl;
    tables.push_back(Table("Стандартный стол", 10000, "IKEA", "Белый", 80, 120, "прямоугольный"));
    tables.push_back(Table("Круглый стол", 15000, "Hoff", "Дуб", 90, 90, "круглый"));
    displayAllTables(tables, "После добавления 2 элементов в конец");
    
    // Добавление в начало (используем insert)
    cout << "\n--- 2. Добавление элементов в НАЧАЛО контейнера ---" << endl;
    tables.insert(tables.begin(), Table("Элитный стол", 50000, "Италия", "Мрамор", 120, 120, "квадратный"));
    tables.insert(tables.begin(), Table("Маленький столик", 3000, "Китай", "Пластик", 40, 40, "круглый"));
    displayAllTables(tables, "После добавления 2 элементов в начало");
    
    // Добавление в середину
    cout << "\n--- 3. Добавление элементов в СЕРЕДИНУ контейнера ---" << endl;
    size_t middlePos = tables.size() / 2;
    tables.insert(tables.begin() + middlePos, Table("Серединный стол", 20000, "Россия", "Вишня", 100, 100, "квадратный"));
    displayAllTables(tables, "После добавления элемента в середину");
    
    // Добавление на определенную позицию
    cout << "\n--- 4. Добавление элемента на ПОЗИЦИЮ 2 (индекс 1) ---" << endl;
    tables.insert(tables.begin() + 1, Table("Стол на позицию 2", 12000, "Польша", "Сосна", 70, 110, "прямоугольный"));
    displayAllTables(tables, "После добавления на позицию 2");
    
    // Добавление нескольких элементов сразу
    cout << "\n--- 5. Добавление НЕСКОЛЬКИХ элементов (3 случайных стола) ---" << endl;
    vector<Table> newTables;
    for (int i = 0; i < 3; i++) {
        newTables.push_back(createTestTable(i + 100));
    }
    tables.insert(tables.end(), newTables.begin(), newTables.end());
    displayAllTables(tables, "После добавления 3 случайных столов");
    
    // 2. Удаление элементов по различным правилам
    
    // Удаление первого элемента
    cout << "\n--- 6. УДАЛЕНИЕ первого элемента ---" << endl;
    if (!tables.empty()) {
        cout << "Удаляем: ";
        tables[0].displayInfo();
        tables.erase(tables.begin());
        displayAllTables(tables, "После удаления первого элемента");
    }
    
    // Удаление последнего элемента
    cout << "\n--- 7. УДАЛЕНИЕ последнего элемента ---" << endl;
    if (!tables.empty()) {
        cout << "Удаляем: ";
        tables.back().displayInfo();
        tables.pop_back();
        displayAllTables(tables, "После удаления последнего элемента");
    }
    
    // Удаление по критерию (удаляем все прямоугольные столы)
    cout << "\n--- 8. УДАЛЕНИЕ по критерию (все прямоугольные столы) ---" << endl;
    int removedCount = 0;
    for (auto it = tables.begin(); it != tables.end(); ) {
        if (it->getShape() == "прямоугольный") {
            cout << "Удаляем прямоугольный стол: " << it->getName() << endl;
            it = tables.erase(it);
            removedCount++;
        } else {
            ++it;
        }
    }
    cout << "Удалено столов: " << removedCount << endl;
    displayAllTables(tables, "После удаления прямоугольных столов");
    
    // Удаление с определенной позиции (удаляем элемент с индексом 2)
    cout << "\n--- 9. УДАЛЕНИЕ с позиции 3 (индекс 2) ---" << endl;
    if (tables.size() > 2) {
        cout << "Удаляем элемент с индексом 2: ";
        tables[2].displayInfo();
        tables.erase(tables.begin() + 2);
        displayAllTables(tables, "После удаления с позиции 3");
    }
    
    // Удаление диапазона элементов (удаляем первые 2 элемента)
    cout << "\n--- 10. УДАЛЕНИЕ диапазона (первые 2 элемента) ---" << endl;
    if (tables.size() >= 2) {
        cout << "Удаляем элементы с индексов 0 и 1" << endl;
        tables.erase(tables.begin(), tables.begin() + 2);
        displayAllTables(tables, "После удаления первых двух элементов");
    }
    
    // 3. Сортировка и переупорядочивание
    
    // Добавим еще несколько элементов для демонстрации сортировки
    cout << "\n--- 11. Добавление дополнительных элементов для сортировки ---" << endl;
    for (int i = 0; i < 5; i++) {
        tables.push_back(createTestTable(i));
    }
    displayAllTables(tables, "Перед сортировкой");
    
    // Сортировка по стоимости (по возрастанию)
    cout << "\n--- 12. СОРТИРОВКА по стоимости (по возрастанию) ---" << endl;
    sort(tables.begin(), tables.end());
    displayAllTables(tables, "После сортировки по стоимости");
    
    // Сортировка по стоимости (по убыванию)
    cout << "\n--- 13. СОРТИРОВКА по стоимости (по убыванию) ---" << endl;
    sort(tables.begin(), tables.end(), [](const Table& a, const Table& b) {
        return a.getCost() > b.getCost();
    });
    displayAllTables(tables, "После сортировки по стоимости (убывание)");
    
    // Сортировка по наименованию
    cout << "\n--- 14. СОРТИРОВКА по наименованию (алфавитный порядок) ---" << endl;
    sort(tables.begin(), tables.end(), [](const Table& a, const Table& b) {
        return a.getName() < b.getName();
    });
    displayAllTables(tables, "После сортировки по наименованию");
    
    // Сортировка по цвету
    cout << "\n--- 15. СОРТИРОВКА по цвету ---" << endl;
    sort(tables.begin(), tables.end(), [](const Table& a, const Table& b) {
        return a.getColor() < b.getColor();
    });
    displayAllTables(tables, "После сортировки по цвету");
    
    // Сортировка по площади столешницы
    cout << "\n--- 16. СОРТИРОВКА по площади столешницы (по возрастанию) ---" << endl;
    sort(tables.begin(), tables.end(), [](const Table& a, const Table& b) {
        return a.getArea() < b.getArea();
    });
    displayAllTables(tables, "После сортировки по площади");
    
    // Переупорядочивание - реверс (обратный порядок)
    cout << "\n--- 17. ПЕРЕУПОРЯДОЧИВАНИЕ (реверс порядка элементов) ---" << endl;
    reverse(tables.begin(), tables.end());
    displayAllTables(tables, "После реверса (обратный порядок)");
    
    // Переупорядочивание - перемешивание (shuffle)
    cout << "\n--- 18. ПЕРЕМЕШИВАНИЕ элементов (random shuffle) ---" << endl;
    random_shuffle(tables.begin(), tables.end());
    displayAllTables(tables, "После перемешивания");
    
    // 4. Дополнительные операции с контейнером
    
    // Поиск элемента по критерию
    cout << "\n--- 19. ПОИСК элемента по критерию (первый круглый стол) ---" << endl;
    auto it = find_if(tables.begin(), tables.end(), [](const Table& t) {
        return t.getShape() == "круглый";
    });
    
    if (it != tables.end()) {
        cout << "Найден круглый стол:" << endl;
        it->displayInfo();
    } else {
        cout << "Круглых столов не найдено" << endl;
    }
    
    // Подсчет элементов по критерию
    cout << "\n--- 20. ПОДСЧЕТ элементов по критерию (количество квадратных столов) ---" << endl;
    int squareCount = count_if(tables.begin(), tables.end(), [](const Table& t) {
        return t.getShape() == "квадратный";
    });
    cout << "Количество квадратных столов: " << squareCount << endl;
    
    // Замена элементов
    cout << "\n--- 21. ЗАМЕНА элемента (увеличиваем цену всех столов на 10%) ---" << endl;
    for_each(tables.begin(), tables.end(), [](Table& t) {
        t.setCost(t.getCost() * 1.1);
    });
    
    // Вывод итогового состояния контейнера
    displayAllTables(tables, "ИТОГОВОЕ СОСТОЯНИЕ КОНТЕЙНЕРА");
    
    // Очистка контейнера
    cout << "\n--- 22. ОЧИСТКА контейнера ---" << endl;
    tables.clear();
    cout << "Контейнер очищен. Размер: " << tables.size() << endl;
    displayAllTables(tables, "Пустой контейнер");
    
    cout << "\n=== Демонстрация работы с контейнером завершена ===" << endl;
    
    return 0;
}