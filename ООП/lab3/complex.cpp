#include "complex.h"

// ==================== РЕАЛИЗАЦИЯ МЕТОДОВ БАЗОВОГО КЛАССА ====================

// Конструктор по умолчанию
ComplexNumber::ComplexNumber() : real(0), imaginary(0) {
    std::cout << "[Базовый класс] Вызван конструктор с параметрами по умолчанию: " 
              << real << " + " << imaginary << "i" << std::endl;
}

// Конструктор с одним параметром
ComplexNumber::ComplexNumber(double r) : real(r), imaginary(0) {
    std::cout << "[Базовый класс] Вызван конструктор с одним параметром: " 
              << real << " + " << imaginary << "i" << std::endl;
}

// Конструктор с двумя параметрами
ComplexNumber::ComplexNumber(double r, double i) : real(r), imaginary(i) {
    std::cout << "[Базовый класс] Вызван конструктор с двумя параметрами: " 
              << real << " + " << imaginary << "i" << std::endl;
}

// Конструктор копирования
ComplexNumber::ComplexNumber(const ComplexNumber& other) 
    : real(other.real), imaginary(other.imaginary) {
    std::cout << "[Базовый класс] Вызван конструктор копирования: " 
              << real << " + " << imaginary << "i" << std::endl;
}

// Деструктор
ComplexNumber::~ComplexNumber() {
    std::cout << "[Базовый класс] Вызван деструктор для числа: " 
              << real << " + " << imaginary << "i" << std::endl;
}

// Метод для ввода с клавиатуры
void ComplexNumber::inputFromKeyboard() {
    std::cout << "Введите действительную часть: ";
    while (!(std::cin >> real)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }
    
    std::cout << "Введите мнимую часть: ";
    while (!(std::cin >> imaginary)) {
        std::cout << "Ошибка! Введите число: ";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }
}

void ComplexNumber::printFields() const {
    std::cout << "Действительная часть: " << real << std::endl;
    std::cout << "Мнимая часть: " << imaginary << std::endl;
}

double ComplexNumber::modulus() const {
    return std::sqrt(real * real + imaginary * imaginary);
}

double ComplexNumber::argument() const {
    return std::atan2(imaginary, real);
}

void ComplexNumber::printAlgebraicForm() const {
    std::cout << std::showpos << real << std::noshowpos;
    
    if (imaginary != 0) {
        if (imaginary > 0)
            std::cout << " + " << imaginary << "i";
        else
            std::cout << " - " << std::abs(imaginary) << "i";
    }
    std::cout << std::endl;
}

void ComplexNumber::printTrigonometricForm() const {
    double r = modulus();
    double theta = argument();
    
    if (r == 0) {
        std::cout << "0" << std::endl;
        return;
    }
    
    std::cout << r << " * (cos(" << theta << ")";
    
    if (std::sin(theta) >= 0)
        std::cout << " + i * sin(" << theta << "))";
    else
        std::cout << " - i * sin(" << std::abs(theta) << "))";
    std::cout << std::endl;
}

void ComplexNumber::printArgumentInDegrees() const {
    double argRad = argument();
    double argDeg = argRad * 180.0 / 3.14159265358979323846;
    std::cout << "Аргумент: " << argRad << " радиан (" << argDeg << "°)" << std::endl;
}

// ==================== РЕАЛИЗАЦИЯ МЕТОДОВ ПРОИЗВОДНОГО КЛАССА ====================

// Конструктор по умолчанию (вызов конструктора базового класса)
ComplexOperations::ComplexOperations() : ComplexNumber() {
    std::cout << "[Производный класс] Вызван конструктор по умолчанию" << std::endl;
}

// Конструктор с одним параметром
ComplexOperations::ComplexOperations(double r) : ComplexNumber(r, 0) {
    std::cout << "[Производный класс] Вызван конструктор с одним параметром: " 
              << r << std::endl;
}

// Конструктор с двумя параметрами
ComplexOperations::ComplexOperations(double r, double i) : ComplexNumber(r, i) {
    std::cout << "[Производный класс] Вызван конструктор с двумя параметрами: " 
              << r << " + " << i << "i" << std::endl;
}

// Конструктор копирования из базового класса
ComplexOperations::ComplexOperations(const ComplexNumber& other) 
    : ComplexNumber(other) {
    std::cout << "[Производный класс] Вызван конструктор копирования из базового класса" 
              << std::endl;
}

// Конструктор копирования
ComplexOperations::ComplexOperations(const ComplexOperations& other) 
    : ComplexNumber(other) {
    std::cout << "[Производный класс] Вызван конструктор копирования" << std::endl;
}

// Деструктор
ComplexOperations::~ComplexOperations() {
    std::cout << "[Производный класс] Вызван деструктор" << std::endl;
}

// Сложение двух объектов производного класса
ComplexOperations ComplexOperations::add(const ComplexOperations& other) const {
    double newReal = this->getReal() + other.getReal();
    double newImag = this->getImaginary() + other.getImaginary();
    
    std::cout << "\nВыполняется операция сложения:" << std::endl;
    std::cout << "  (" << getReal() << " + " << getImaginary() << "i) + ";
    std::cout << "(" << other.getReal() << " + " << other.getImaginary() << "i) = ";
    std::cout << "(" << newReal << " + " << newImag << "i)" << std::endl;
    
    return ComplexOperations(newReal, newImag);
}

// Вычитание двух объектов производного класса
ComplexOperations ComplexOperations::subtract(const ComplexOperations& other) const {
    double newReal = this->getReal() - other.getReal();
    double newImag = this->getImaginary() - other.getImaginary();
    
    std::cout << "\nВыполняется операция вычитания:" << std::endl;
    std::cout << "  (" << getReal() << " + " << getImaginary() << "i) - ";
    std::cout << "(" << other.getReal() << " + " << other.getImaginary() << "i) = ";
    std::cout << "(" << newReal << " + " << newImag << "i)" << std::endl;
    
    return ComplexOperations(newReal, newImag);
}

// Сложение с объектом базового класса
ComplexOperations ComplexOperations::add(const ComplexNumber& other) const {
    double newReal = this->getReal() + other.getReal();
    double newImag = this->getImaginary() + other.getImaginary();
    
    std::cout << "\nВыполняется операция сложения (с базовым классом):" << std::endl;
    std::cout << "  (" << getReal() << " + " << getImaginary() << "i) + ";
    other.printAlgebraicForm();
    std::cout << "  = (" << newReal << " + " << newImag << "i)" << std::endl;
    
    return ComplexOperations(newReal, newImag);
}

// Вычитание с объектом базового класса
ComplexOperations ComplexOperations::subtract(const ComplexNumber& other) const {
    double newReal = this->getReal() - other.getReal();
    double newImag = this->getImaginary() - other.getImaginary();
    
    std::cout << "\nВыполняется операция вычитания (с базовым классом):" << std::endl;
    std::cout << "  (" << getReal() << " + " << getImaginary() << "i) - ";
    other.printAlgebraicForm();
    std::cout << "  = (" << newReal << " + " << newImag << "i)" << std::endl;
    
    return ComplexOperations(newReal, newImag);
}

// Метод для демонстрации всех характеристик
void ComplexOperations::demonstrateAll() const {
    std::cout << "\n--- Характеристики комплексного числа ---" << std::endl;
    printFields();
    std::cout << "Алгебраическая форма: ";
    printAlgebraicForm();
    std::cout << "Тригонометрическая форма: ";
    printTrigonometricForm();
    std::cout << "Модуль: " << modulus() << std::endl;
    printArgumentInDegrees();
}

// Функция для создания красивого разделителя
void printSeparator(char ch, int length) {
    std::cout << std::string(length, ch) << std::endl;
}