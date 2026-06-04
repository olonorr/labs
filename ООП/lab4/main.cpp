#include "complex.h"
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::cout << "\n\t\tКОМПЛЕКСНЫЕ ЧИСЛА (С ПЕРЕГРУЖЕННЫМИ ОПЕРАТОРАМИ)\n" << std::endl;
    printSeparator('=', 80);
    
    // ========== ДЕМОНСТРАЦИЯ ОПЕРАТОРА + ==========
    std::cout << "\n1. ДЕМОНСТРАЦИЯ ОПЕРАТОРА СЛОЖЕНИЯ (+):\n" << std::endl;
    
    ComplexOperations num1(4.0, 5.0);
    ComplexOperations num2(2.0, 3.0);
    ComplexOperations num3(1.0, 1.0);
    
    std::cout << "Исходные числа:" << std::endl;
    std::cout << "  num1 = "; num1.printAlgebraicForm();
    std::cout << "  num2 = "; num2.printAlgebraicForm();
    std::cout << "  num3 = "; num3.printAlgebraicForm();
    
    // Использование оператора +
    ComplexOperations sum1 = num1 + num2;
    std::cout << "\nРезультат num1 + num2: ";
    sum1.printAlgebraicForm();
    
    ComplexOperations sum2 = num1 + num2 + num3;
    std::cout << "\nРезультат num1 + num2 + num3: ";
    sum2.printAlgebraicForm();
    
    // ========== ДЕМОНСТРАЦИЯ ОПЕРАТОРА - ==========
    printSeparator('=', 80);
    std::cout << "\n2. ДЕМОНСТРАЦИЯ ОПЕРАТОРА ВЫЧИТАНИЯ (-):\n" << std::endl;
    
    ComplexOperations diff1 = num1 - num2;
    std::cout << "\nРезультат num1 - num2: ";
    diff1.printAlgebraicForm();
    
    ComplexOperations diff2 = num1 - num2 - num3;
    std::cout << "\nРезультат num1 - num2 - num3: ";
    diff2.printAlgebraicForm();
    
    // ========== ДЕМОНСТРАЦИЯ ОПЕРАТОРА == ==========
    printSeparator('=', 80);
    std::cout << "\n3. ДЕМОНСТРАЦИЯ ОПЕРАТОРА СРАВНЕНИЯ (==):\n" << std::endl;
    
    ComplexOperations equal1(4.0, 5.0);
    ComplexOperations equal2(4.0, 5.0);
    ComplexOperations equal3(2.0, 3.0);
    
    std::cout << "Числа:" << std::endl;
    std::cout << "  equal1 = "; equal1.printAlgebraicForm();
    std::cout << "  equal2 = "; equal2.printAlgebraicForm();
    std::cout << "  equal3 = "; equal3.printAlgebraicForm();
    
    bool res1 = (equal1 == equal2);
    bool res2 = (equal1 == equal3);
    
    std::cout << "\nРезультаты сравнения:" << std::endl;
    std::cout << "  equal1 == equal2: " << (res1 ? "true (числа равны)" : "false") << std::endl;
    std::cout << "  equal1 == equal3: " << (res2 ? "true" : "false (числа не равны)") << std::endl;
    
    // ========== ДЕМОНСТРАЦИЯ ОПЕРАТОРА != ==========
    printSeparator('=', 80);
    std::cout << "\n4. ДЕМОНСТРАЦИЯ ОПЕРАТОРА НЕРАВЕНСТВА (!=):\n" << std::endl;
    
    bool res3 = (equal1 != equal2);
    bool res4 = (equal1 != equal3);
    
    std::cout << "Результаты сравнения:" << std::endl;
    std::cout << "  equal1 != equal2: " << (res3 ? "true" : "false (числа равны)") << std::endl;
    std::cout << "  equal1 != equal3: " << (res4 ? "true (числа не равны)" : "false") << std::endl;
    
    // ========== СМЕШАННЫЕ ОПЕРАЦИИ ==========
    printSeparator('=', 80);
    std::cout << "\n5. СМЕШАННЫЕ ОПЕРАЦИИ С ИСПОЛЬЗОВАНИЕМ РАЗНЫХ ОПЕРАТОРОВ:\n" << std::endl;
    
    ComplexOperations a(10.0, 0.0);
    ComplexOperations b(3.0, 4.0);
    ComplexOperations c(2.0, 1.0);
    
    std::cout << "a = "; a.printAlgebraicForm();
    std::cout << "b = "; b.printAlgebraicForm();
    std::cout << "c = "; c.printAlgebraicForm();
    
    ComplexOperations result1 = (a + b) - c;
    std::cout << "\nРезультат (a + b) - c: ";
    result1.printAlgebraicForm();
    
    ComplexOperations result2 = (a - b) + c;
    std::cout << "\nРезультат (a - b) + c: ";
    result2.printAlgebraicForm();
    
    // ========== РАБОТА С БАЗОВЫМ КЛАССОМ ==========
    printSeparator('=', 80);
    std::cout << "\n6. ОПЕРАЦИИ С ОБЪЕКТАМИ БАЗОВОГО КЛАССА:\n" << std::endl;
    
    ComplexOperations derived(5.0, 7.0);
    ComplexNumber base1(2.0, 3.0);
    ComplexNumber base2(5.0, 7.0);
    
    std::cout << "Производный класс derived: "; derived.printAlgebraicForm();
    std::cout << "Базовый класс base1: "; base1.printAlgebraicForm();
    std::cout << "Базовый класс base2: "; base2.printAlgebraicForm();
    
    // derived + base
    ComplexOperations mixSum = derived + base1;
    std::cout << "derived + base1 = "; mixSum.printAlgebraicForm();
    
    // derived - base
    ComplexOperations mixDiff = derived - base1;
    std::cout << "derived - base1 = "; mixDiff.printAlgebraicForm();
    
    // base + derived (используем дружественную функцию)
    ComplexOperations mixSum2 = base1 + derived;
    std::cout << "base1 + derived = "; mixSum2.printAlgebraicForm();
    
    // base - derived (используем дружественную функцию)
    ComplexOperations mixDiff2 = base1 - derived;
    std::cout << "base1 - derived = "; mixDiff2.printAlgebraicForm();
    
    // Сравнение
    bool eq1 = (derived == base1);
    bool eq2 = (derived == base2);
    
    std::cout << "\nРезультаты сравнения:" << std::endl;
    std::cout << "derived == base1: " << (eq1 ? "true" : "false") << std::endl;
    std::cout << "derived == base2: " << (eq2 ? "true" : "false") << std::endl;
    
    bool neq1 = (derived != base1);
    bool neq2 = (base1 != derived);
    
    std::cout << "derived != base1: " << (neq1 ? "true" : "false") << std::endl;
    std::cout << "base1 != derived: " << (neq2 ? "true" : "false") << std::endl;
    
    // ========== ПРОВЕРКА НА РАВЕНСТВО С НУЛЕМ ==========
    printSeparator('=', 80);
    std::cout << "\n7. ПРОВЕРКА НА РАВЕНСТВО/НЕРАВЕНСТВО С РАЗНЫМИ ЧИСЛАМИ:\n" << std::endl;
    
    ComplexOperations zero1(0, 0);
    ComplexOperations zero2(0, 0);
    ComplexOperations nonZero(3, 4);
    
    std::cout << "zero1 = "; zero1.printAlgebraicForm();
    std::cout << "zero2 = "; zero2.printAlgebraicForm();
    std::cout << "nonZero = "; nonZero.printAlgebraicForm();
    
    bool isEqual = (zero1 == zero2);
    bool isNotEqual = (zero1 != nonZero);
    
    std::cout << "\nzero1 == zero2: " << (isEqual ? "true" : "false") << std::endl;
    std::cout << "zero1 != nonZero: " << (isNotEqual ? "true" : "false") << std::endl;
    
    // ========== ВВОД С КЛАВИАТУРЫ И ПРОВЕРКА ==========
    printSeparator('=', 80);
    std::cout << "\n8. ВВОД С КЛАВИАТУРЫ И ИСПОЛЬЗОВАНИЕ ОПЕРАТОРОВ:\n" << std::endl;
    
    ComplexOperations userNum1, userNum2;
    std::cout << "Введите первое комплексное число:" << std::endl;
    userNum1.inputFromKeyboard();
    std::cout << "\nВведите второе комплексное число:" << std::endl;
    userNum2.inputFromKeyboard();
    
    std::cout << "\nВведенные числа:" << std::endl;
    std::cout << "  Число 1: "; userNum1.printAlgebraicForm();
    std::cout << "  Число 2: "; userNum2.printAlgebraicForm();
    
    ComplexOperations userSum = userNum1 + userNum2;
    std::cout << "\nСумма: "; userSum.printAlgebraicForm();
    
    ComplexOperations userDiff = userNum1 - userNum2;
    std::cout << "Разность: "; userDiff.printAlgebraicForm();
    
    if (userNum1 == userNum2) {
        std::cout << "\nЧисла равны!" << std::endl;
    } else {
        std::cout << "\nЧисла не равны!" << std::endl;
    }
    
    // ========== ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ ==========
    printSeparator('=', 80);
    std::cout << "\n9. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ С ОПЕРАТОРАМИ:\n" << std::endl;
    
    ComplexOperations complex1(0, 5);
    ComplexOperations complex2(0, 3);
    ComplexOperations complex3(0, 2);
    
    std::cout << "Чисто мнимые числа:" << std::endl;
    std::cout << "  complex1 = "; complex1.printAlgebraicForm();
    std::cout << "  complex2 = "; complex2.printAlgebraicForm();
    
    ComplexOperations imaginarySum = complex1 + complex2;
    std::cout << "\nСумма мнимых чисел: "; imaginarySum.printAlgebraicForm();
    
    ComplexOperations imaginaryDiff = complex1 - complex2;
    std::cout << "Разность мнимых чисел: "; imaginaryDiff.printAlgebraicForm();
    
    // Цепочка операций
    ComplexOperations chain = complex1 - complex2 + complex3;
    std::cout << "\nРезультат complex1 - complex2 + complex3: ";
    chain.printAlgebraicForm();
    
    // ========== ЗАВЕРШЕНИЕ ==========
    printSeparator('=', 80);
    std::cout << "\nПрограмма завершена. Нажмите Enter для выхода...";
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}