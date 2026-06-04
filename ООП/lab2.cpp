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
    // Конструктор по умолчанию (с параметрами по умолчанию)
    ComplexNumber() : real(0), imaginary(0) {
        std::cout << "Вызван конструктор с параметрами по умолчанию: " 
                  << real << " + " << imaginary << "i" << std::endl;
    }
    
    // Конструктор с одним параметром
    ComplexNumber(double r) : ComplexNumber(r, 0) {
        std::cout << "Вызван конструктор с одним параметром (действительная часть): " 
                  << real << std::endl;
    }
    
    // Конструктор с двумя параметрами
    ComplexNumber(double r, double i) : real(r), imaginary(i) {
        std::cout << "Вызван конструктор с двумя параметрами: " 
                  << real << " + " << imaginary << "i" << std::endl;
    }
    
    // Конструктор копирования
    ComplexNumber(const ComplexNumber& other) : real(other.real), imaginary(other.imaginary) {
        std::cout << "Вызван конструктор копирования: " 
                  << real << " + " << imaginary << "i" << std::endl;
    }
    
    // Деструктор
    ~ComplexNumber() {
        std::cout << "Вызван деструктор для числа: " 
                  << real << " + " << imaginary << "i" << std::endl;
    }

    // Методы для задания значений полей с клавиатуры
    void inputFromKeyboard() {
        std::cout << "Введите действительную часть: ";
        while (!(std::cin >> real)) {
            std::cout << "Ошибка! Введите число: ";
            std::cin.clear();

            // Очищаем буфер от '\n' и всего остального
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
        
        std::cout << "Введите мнимую часть: ";
        while (!(std::cin >> imaginary)) {
            std::cout << "Ошибка! Введите число: ";
            std::cin.clear();

            // Очищаем буфер от '\n' и всего остального
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
void demonstrateComplexNumber(const ComplexNumber& num, const std::string& name) {
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
    printSeparator('=', 60);
    
    // Конструктор с параметрами по умолчанию
    std::cout << "\n1. СОЗДАНИЕ ОБЪЕКТОВ РАЗЛИЧНЫМИ КОНСТРУКТОРАМИ:\n" << std::endl;
    
    std::cout << "A) Конструктор с параметрами по умолчанию (без аргументов):" << std::endl;
    ComplexNumber defaultNum;
    demonstrateComplexNumber(defaultNum, "объекта, созданного конструктором по умолчанию");
    
    std::cout << "\nB) Конструктор с параметрами по умолчанию (с двумя аргументами):" << std::endl;
    ComplexNumber paramNum(2.5, 3.7);
    demonstrateComplexNumber(paramNum, "объекта, созданного конструктором с параметрами");
    
    std::cout << "\nC) Конструктор с одним параметром (использует параметры по умолчанию):" << std::endl;
    ComplexNumber singleParamNum(5.0);
    demonstrateComplexNumber(singleParamNum, "объекта, созданного конструктором с одним параметром");
    
    // Демонстрация конструктор копирования
    std::cout << "\nДЕМОНСТРАЦИЯ КОНСТРУКТОРА КОПИРОВАНИЯ:" << std::endl;
    ComplexNumber original(7.0, 8.0);
    std::cout << "\nОригинальный объект: ";
    original.printAlgebraicForm();
    
    ComplexNumber copyNum(original);
    std::cout << "\nСкопированный объект: ";
    copyNum.printAlgebraicForm();
    demonstrateComplexNumber(copyNum, "объекта, созданного конструктором копирования");
    
    //Ручной ввод данных
    std::cout << "\nВВОД ДАННЫХ С КЛАВИАТУРЫ:" << std::endl;
    ComplexNumber inputNum;
    std::cout << "Введите данные для комплексного числа:" << std::endl;
    inputNum.inputFromKeyboard();
    demonstrateComplexNumber(inputNum, "введенного числа");
    
    // Дополнительные случаи
    std::cout << "\nДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ:" << std::endl;
    
    ComplexNumber negativeNum(-2.5, -1.5);
    demonstrateComplexNumber(negativeNum, "отрицательного числа");
    
    ComplexNumber zeroNum(0, 0);
    demonstrateComplexNumber(zeroNum, "нулевого комплексного числа");
    
    ComplexNumber pureImaginary(0, 5.0);
    demonstrateComplexNumber(pureImaginary, "чисто мнимого числа");
    
    // Демонстрация работы деструкторов (автоматически вызовутся при выходе из области видимости)
    std::cout << "\nВЫЗОВ ДЕСТРУКТОРОВ..." << std::endl;
    printSeparator('=', 60);
    
    std::cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}