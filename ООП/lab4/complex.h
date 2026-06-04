#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

class ComplexNumber {
protected:
    double real;      // Действительная часть
    double imaginary; // Мнимая часть

public:
    // Конструкторы
    ComplexNumber();
    ComplexNumber(double r);
    ComplexNumber(double r, double i);
    ComplexNumber(const ComplexNumber& other);
    
    // Деструктор
    virtual ~ComplexNumber();
    
    // Методы для задания значений полей с клавиатуры
    void inputFromKeyboard();
    
    // Метод для вывода значений полей
    void printFields() const;
    
    // Метод для вычисления модуля комплексного числа
    double modulus() const;
    
    // Метод для вычисления аргумента комплексного числа
    double argument() const;
    
    // Метод для вывода числа в алгебраической форме (a + bi)
    void printAlgebraicForm() const;
    
    // Метод для вывода числа в тригонометрической форме
    void printTrigonometricForm() const;
    
    // Метод для красивого вывода аргумента в градусах
    void printArgumentInDegrees() const;
    
    // Геттеры для доступа к полям из производного класса
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    
    // Сеттеры (могут понадобиться для операций)
    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }
};

// Производный класс для выполнения операций с комплексными числами
class ComplexOperations : public ComplexNumber {
public:
    // Конструкторы производного класса
    ComplexOperations();
    ComplexOperations(double r);
    ComplexOperations(double r, double i);
    ComplexOperations(const ComplexNumber& other);
    ComplexOperations(const ComplexOperations& other);
    
    // Деструктор
    ~ComplexOperations();
    
    // Методы для сложения и вычитания (оставлены для совместимости)
    ComplexOperations add(const ComplexOperations& other) const;
    ComplexOperations subtract(const ComplexOperations& other) const;
    
    // Перегруженные методы для работы с базовым классом
    ComplexOperations add(const ComplexNumber& other) const;
    ComplexOperations subtract(const ComplexNumber& other) const;
    
    // ПЕРЕГРУЖЕННЫЕ ОПЕРАТОРЫ
    // Оператор сложения
    ComplexOperations operator+(const ComplexOperations& other) const;
    
    // Оператор вычитания
    ComplexOperations operator-(const ComplexOperations& other) const;
    
    // Оператор сравнения ==
    bool operator==(const ComplexOperations& other) const;
    
    // Оператор сравнения !=
    bool operator!=(const ComplexOperations& other) const;
    
    // Перегруженные операторы для работы с базовым классом
    ComplexOperations operator+(const ComplexNumber& other) const;
    ComplexOperations operator-(const ComplexNumber& other) const;
    
    bool operator==(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;
    
    // Метод для демонстрации всех характеристик
    void demonstrateAll() const;
    
    // Дружественные функции для операторов с разными типами (если нужно)
    friend ComplexOperations operator+(const ComplexNumber& left, const ComplexOperations& right);
    friend ComplexOperations operator-(const ComplexNumber& left, const ComplexOperations& right);
    friend bool operator==(const ComplexNumber& left, const ComplexOperations& right);
    friend bool operator!=(const ComplexNumber& left, const ComplexOperations& right);
};

// Дружественные функции (объявление)
ComplexOperations operator+(const ComplexNumber& left, const ComplexOperations& right);
ComplexOperations operator-(const ComplexNumber& left, const ComplexOperations& right);
bool operator==(const ComplexNumber& left, const ComplexOperations& right);
bool operator!=(const ComplexNumber& left, const ComplexOperations& right);

// Функция для создания красивого разделителя
void printSeparator(char ch = '=', int length = 50);

#endif // COMPLEX_H