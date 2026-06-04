#include <iostream>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <limits>

class ComplexNumber {
private:
    double real;      // Действительная часть
    double imaginary; // Мнимая часть

public:
    // Конструкторы
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Методы для задания значений полей с клавиатуры
    void inputFromKeyboard() {
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

    // Метод для вывода значений полей
    void printFields() const {
        std::cout << "Действительная часть: " << real << std::endl;
        std::cout << "Мнимая часть: " << imaginary << std::endl;
    }

    // Метод для вычисления модуля комплексного числа
    double modulus() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Метод для вычисления аргумента комплексного числа
    double argument() const {
        return std::atan2(imaginary, real);
    }

    // Метод для вывода числа в алгебраической форме (a + bi)
    void printAlgebraicForm() const {
        std::cout << std::showpos << real << std::noshowpos;
        
        if (imaginary != 0) {
            if (imaginary > 0)
                std::cout << " + " << imaginary << "i";
            else
                std::cout << " - " << std::abs(imaginary) << "i";
        }
        std::cout << std::endl;
    }

    // Метод для вывода числа в тригонометрической форме
    void printTrigonometricForm() const {
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

    // Дополнительный метод для красивого вывода аргумента в градусах
    void printArgumentInDegrees() const {
        double argRad = argument();
        double argDeg = argRad * 180.0 / 3.14159265358979323846;
        std::cout << "Аргумент: " << argRad << " радиан (" << argDeg << "°)" << std::endl;
    }
};

// Функция для создания красивого разделителя
void printSeparator(char ch = '=', int length = 50) {
    std::cout << std::string(length, ch) << std::endl;
}

// Функция для демонстрации всех методов для заданного комплексного числа
void demonstrateComplexNumber(ComplexNumber& num, const std::string& name) {
    printSeparator();
    std::cout << "Демонстрация для " << name << ":" << std::endl;
    printSeparator('-');
    
    std::cout << "\nЗначения полей:" << std::endl;
    num.printFields();
    
    std::cout << "\nПредставление числа:" << std::endl;
    std::cout << "Алгебраическая форма: ";
    num.printAlgebraicForm();
    
    std::cout << "Тригонометрическая форма: ";
    num.printTrigonometricForm();
    
    std::cout << "\nХарактеристики числа:" << std::endl;
    std::cout << "Модуль: " << num.modulus() << std::endl;
    num.printArgumentInDegrees();
    
    printSeparator();
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::cout << "\n\t\tКОМПЛЕКСНЫЕ ЧИСЛА\n" << std::endl;
    
    // Создание первого объекта через конструктор с параметрами
    ComplexNumber num1(3.0, 4.0);
    demonstrateComplexNumber(num1, "числа 3 + 4i");
    
    // Создание второго объекта через конструктор по умолчанию и ручной ввод
    ComplexNumber num2;
    std::cout << "Введите данные для второго комплексного числа:" << std::endl;
    num2.inputFromKeyboard();
    demonstrateComplexNumber(num2, "введенного числа");
    
    // Создание третьего объекта для демонстрации разных случаев
    ComplexNumber num3(-2.5, -1.5);
    demonstrateComplexNumber(num3, "числа -2.5 - 1.5i");
    
    // Дополнительная демонстрация с нулевым числом
    ComplexNumber num4(0, 0);
    demonstrateComplexNumber(num4, "нулевого комплексного числа");
    
    std::cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}