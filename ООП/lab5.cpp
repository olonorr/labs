#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>

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
    Table(const string& n, double c, const string& m, 
          const string& col, double w, double l, const string& sh)
        : Furniture(n, c, m), color(col), width(w), length(l), shape(sh) {}
    
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
    double getArea() const { return width * length; }
    
    // Метод для изменения цены
    void setCost(double newCost) { cost = newCost; }
};

// Производный класс Шкаф
class Wardrobe : public Furniture {
private:
    string model;       // модель
    double height;      // высота
    double width;       // ширина
    double depth;       // глубина

public:
    // Конструктор
    Wardrobe(const string& n, double c, const string& m,
             const string& mod, double h, double w, double d)
        : Furniture(n, c, m), model(mod), height(h), width(w), depth(d) {}
    
    // Переопределение виртуальной функции вывода
    void print() const override {
        Furniture::print();
        cout << "Модель: " << model << endl;
        cout << "Размеры (высота x ширина x глубина): " 
             << height << " x " << width << " x " << depth << " см" << endl;
    }
    
    // Реализация чистой виртуальной функции
    void displayInfo() const override {
        cout << "\n=== Информация о шкафе ===" << endl;
        print();
        cout << "==========================" << endl;
    }
    
    // Дополнительные методы
    double getVolume() const { return height * width * depth; }
    
    // Метод для изменения цены
    void setCost(double newCost) { cost = newCost; }
};

// Функция для демонстрации полиморфизма
void showFurnitureInfo(const Furniture& furniture) {
    furniture.displayInfo();
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    cout << "=== Демонстрация работы с классами ===" << endl;
    
    // 1. Создание объектов класса Стол
    cout << "\n--- Создание объектов Стол ---" << endl;
    Table table1("Обеденный стол", 15000, "IKEA", "Дуб", 80, 120, "прямоугольный");
    Table table2("Журнальный столик", 8000, "Hoff", "Белый", 60, 60, "круглый");
    Table table3("Письменный стол", 12000, "Леруа Мерлен", "Черный", 70, 140, "квадратный");
    Table table4("Кофейный столик", 9500, "Mebel City", "Серый", 50, 50, "круглый");
    Table table5("Компьютерный стол", 18000, "Дятьково", "Орех", 90, 150, "прямоугольный");
    
    // Демонстрация работы методов
    cout << "\n--- Демонстрация методов для Стол ---" << endl;
    table1.displayInfo();
    cout << "Площадь стола: " << table1.getArea() << " кв.см" << endl;
    
    table2.displayInfo();
    cout << "Площадь стола: " << table2.getArea() << " кв.см" << endl;
    
    // 2. Создание константного объекта (для одного из производных классов)
    cout << "\n--- Константный объект Шкаф ---" << endl;
    const Wardrobe constWardrobe("Шкаф-купе", 35000, "Шатура", "Элегант", 220, 180, 60);
    constWardrobe.displayInfo();
    // constWardrobe.setCost(40000); // Ошибка: нельзя изменять константный объект
    cout << "Объем шкафа: " << constWardrobe.getVolume() << " куб.см" << endl;
    
    // 3. Создание объектов класса Шкаф
    cout << "\n--- Создание объектов Шкаф ---" << endl;
    Wardrobe wardrobe1("Шкаф для одежды", 25000, "IKEA", "PAX", 200, 100, 50);
    Wardrobe wardrobe2("Книжный шкаф", 18000, "Хофф", "Классик", 190, 80, 35);
    
    // Демонстрация работы методов для шкафа
    cout << "\n--- Демонстрация методов для Шкаф ---" << endl;
    wardrobe1.displayInfo();
    cout << "Объем шкафа: " << wardrobe1.getVolume() << " куб.см" << endl;
    
    wardrobe2.displayInfo();
    cout << "Объем шкафа: " << wardrobe2.getVolume() << " куб.см" << endl;
    
    // 4. Полиморфное поведение
    cout << "\n--- Полиморфизм (функция принимает ссылку на базовый класс) ---" << endl;
    showFurnitureInfo(table1);
    showFurnitureInfo(wardrobe1);
    
    // 5. Динамический массив (вектор) для объектов класса Стол
    cout << "\n=== Работа с вектором столов ===" << endl;
    vector<Table> tables;
    
    // Добавление столов в вектор
    tables.push_back(table1);
    tables.push_back(table2);
    tables.push_back(table3);
    tables.push_back(table4);
    tables.push_back(table5);
    
    // Вывод всех столов
    cout << "\nВсе столы в векторе:" << endl;
    for (size_t i = 0; i < tables.size(); i++) {
        cout << "\nСтол #" << i + 1 << ":" << endl;
        tables[i].displayInfo();
    }
    
    // Модификация вектора: оставляем только круглые столы
    cout << "\n--- Фильтрация: оставляем только круглые столы ---" << endl;
    
    // Используем итератор для удаления не-круглых столов
    for (auto it = tables.begin(); it != tables.end(); ) {
        if (it->getShape() != "круглый") {
            it = tables.erase(it);
        } else {
            ++it;
        }
    }
    
    // Вывод отфильтрованного вектора
    cout << "\nПосле фильтрации (только круглые столы):" << endl;
    if (tables.empty()) {
        cout << "Вектор пуст (нет круглых столов)" << endl;
    } else {
        for (size_t i = 0; i < tables.size(); i++) {
            cout << "\nСтол #" << i + 1 << ":" << endl;
            tables[i].displayInfo();
        }
    }
    
    // 6. Дополнительная демонстрация изменения данных
    cout << "\n--- Изменение стоимости стола ---" << endl;
    if (!tables.empty()) {
        cout << "Старая стоимость: " << tables[0].getCost() << " руб." << endl;
        tables[0].setCost(tables[0].getCost() * 0.9); // Скидка 10%
        cout << "Новая стоимость (со скидкой): " << tables[0].getCost() << " руб." << endl;
        tables[0].displayInfo();
    }
    
    // 7. Демонстрация работы с указателями на базовый класс
    cout << "\n=== Работа с массивом указателей на базовый класс ===" << endl;
    Furniture* furnitureArray[4];
    furnitureArray[0] = &table1;
    furnitureArray[1] = &table2;
    furnitureArray[2] = &wardrobe1;
    furnitureArray[3] = &wardrobe2;
    
    for (int i = 0; i < 4; i++) {
        furnitureArray[i]->displayInfo();
        cout << endl;
    }
    
    cout << "\n=== Программа завершена ===" << endl;
    
    return 0;
}