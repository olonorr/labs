#include "complex.h"
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::cout << "\n\t\tКОМПЛЕКСНЫЕ ЧИСЛА (С ПРОИЗВОДНЫМ КЛАССОМ)\n" << std::endl;
    printSeparator('=', 70);
    
    // ========== ДЕМОНСТРАЦИЯ БАЗОВОГО КЛАССА ==========
    std::cout << "\n1. ДЕМОНСТРАЦИЯ БАЗОВОГО КЛАССА ComplexNumber:\n" << std::endl;
    
    std::cout << "A) Создание объектов различными конструкторами:" << std::endl;
    ComplexNumber base1;
    ComplexNumber base2(3.5);
    ComplexNumber base3(2.0, 4.0);
    ComplexNumber base4(base3);
    
    printSeparator('-', 70);
    std::cout << "\nB) Демонстрация методов базового класса:" << std::endl;
    std::cout << "Число base3: ";
    base3.printAlgebraicForm();
    std::cout << "Модуль: " << base3.modulus() << std::endl;
    base3.printArgumentInDegrees();
    base3.printTrigonometricForm();
    
    // ========== ДЕМОНСТРАЦИЯ ПРОИЗВОДНОГО КЛАССА ==========
    printSeparator('=', 70);
    std::cout << "\n2. ДЕМОНСТРАЦИЯ ПРОИЗВОДНОГО КЛАССА ComplexOperations:\n" << std::endl;
    
    std::cout << "A) Создание объектов различными конструкторами:" << std::endl;
    ComplexOperations op1;                           // Конструктор по умолчанию
    ComplexOperations op2(5.0);                      // Конструктор с одним параметром
    ComplexOperations op3(3.0, 4.0);                 // Конструктор с двумя параметрами
    ComplexOperations op4(op3);                      // Конструктор копирования
    ComplexOperations op5(base3);                    // Конструктор копирования из базового класса
    
    printSeparator('-', 70);
    std::cout << "\nB) Демонстрация всех методов производного класса:" << std::endl;
    
    std::cout << "\nОбъект op3: ";
    op3.demonstrateAll();
    
    std::cout << "\nОбъект op2: ";
    op2.demonstrateAll();
    
    // ========== ДЕМОНСТРАЦИЯ ОПЕРАЦИЙ СЛОЖЕНИЯ И ВЫЧИТАНИЯ ==========
    printSeparator('=', 70);
    std::cout << "\n3. ДЕМОНСТРАЦИЯ ОПЕРАЦИЙ СЛОЖЕНИЯ И ВЫЧИТАНИЯ:\n" << std::endl;
    
    ComplexOperations num1(4.0, 5.0);
    ComplexOperations num2(2.0, 3.0);
    
    std::cout << "Исходные числа:" << std::endl;
    std::cout << "  num1: ";
    num1.printAlgebraicForm();
    std::cout << "  num2: ";
    num2.printAlgebraicForm();
    
    // Сложение
    std::cout << "\n--- СЛОЖЕНИЕ КОМПЛЕКСНЫХ ЧИСЕЛ ---" << std::endl;
    ComplexOperations sum1 = num1.add(num2);
    std::cout << "Результат сложения: ";
    sum1.printAlgebraicForm();
    sum1.demonstrateAll();
    
    // Вычитание
    std::cout << "\n--- ВЫЧИТАНИЕ КОМПЛЕКСНЫХ ЧИСЕЛ ---" << std::endl;
    ComplexOperations diff1 = num1.subtract(num2);
    std::cout << "Результат вычитания: ";
    diff1.printAlgebraicForm();
    diff1.demonstrateAll();
    
    // ========== ОПЕРАЦИИ С ОБЪЕКТАМИ БАЗОВОГО КЛАССА ==========
    printSeparator('=', 70);
    std::cout << "\n4. ОПЕРАЦИИ С ИСПОЛЬЗОВАНИЕМ ОБЪЕКТОВ БАЗОВОГО КЛАССА:\n" << std::endl;
    
    ComplexOperations num3(7.0, 1.0);
    ComplexNumber baseNum(2.0, 2.0);
    
    std::cout << "Объект производного класса num3: ";
    num3.printAlgebraicForm();
    std::cout << "Объект базового класса baseNum: ";
    baseNum.printAlgebraicForm();
    
    ComplexOperations sum2 = num3.add(baseNum);
    std::cout << "Результат сложения: ";
    sum2.printAlgebraicForm();
    
    ComplexOperations diff2 = num3.subtract(baseNum);
    std::cout << "Результат вычитания: ";
    diff2.printAlgebraicForm();
    
    // ========== ВВОД С КЛАВИАТУРЫ ==========
    printSeparator('=', 70);
    std::cout << "\n5. ВВОД ДАННЫХ С КЛАВИАТУРЫ ДЛЯ ПРОИЗВОДНОГО КЛАССА:\n" << std::endl;
    
    ComplexOperations userNum;
    std::cout << "Введите данные для комплексного числа:" << std::endl;
    userNum.inputFromKeyboard();
    userNum.demonstrateAll();
    
    // ========== ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ ==========
    printSeparator('=', 70);
    std::cout << "\n6. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ:\n" << std::endl;
    
    ComplexOperations negativeOp(-3.0, -2.0);
    negativeOp.demonstrateAll();
    
    ComplexOperations zeroOp(0, 0);
    zeroOp.demonstrateAll();
    
    ComplexOperations pureImagOp(0, 7.0);
    pureImagOp.demonstrateAll();
    
    // ========== ЦЕПОЧКА ОПЕРАЦИЙ ==========
    printSeparator('=', 70);
    std::cout << "\n7. ЦЕПОЧКА ОПЕРАЦИЙ (сложение и вычитание):\n" << std::endl;
    
    ComplexOperations a(10.0, 0.0);
    ComplexOperations b(3.0, 4.0);
    ComplexOperations c(1.0, 1.0);
    
    std::cout << "a = "; a.printAlgebraicForm();
    std::cout << "b = "; b.printAlgebraicForm();
    std::cout << "c = "; c.printAlgebraicForm();
    
    ComplexOperations result = a.add(b).subtract(c);
    std::cout << "\nРезультат (a + b - c): ";
    result.printAlgebraicForm();
    result.demonstrateAll();
    
    // ========== ЗАВЕРШЕНИЕ ==========
    printSeparator('=', 70);
    std::cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}