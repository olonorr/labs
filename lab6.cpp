#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// СПОСОБ 1: Обращение к элементам массива через указатели
// Формальные параметры: указатель на int и размерность
int diffNegativePositive_ptr(int *arr, int size) {
    int negativeCount = 0;
    int positiveCount = 0;
    
    // Обращение через указатели (арифметика указателей)
    for (int i = 0; i < size; i++) {
        if (*(arr + i) < 0) {        // через указатель с арифметикой
            negativeCount++;
        } else if (*(arr + i) > 0) {  // через указатель с арифметикой
            positiveCount++;
        }
        // нули не учитываем
    }
    
    return negativeCount - positiveCount;
}

// СПОСОБ 2: Обращение к элементам массива обычным способом
// Формальные параметры: массив (с указанием размера) и его размерность
int diffNegativePositive_arr(int arr[], int size) {
    int negativeCount = 0;
    int positiveCount = 0;
    
    // Обычное обращение через индексы
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negativeCount++;
        } else if (arr[i] > 0) {
            positiveCount++;
        }
    }
    
    return negativeCount - positiveCount;
}

// Функция для вывода одномерного массива
void printArray(const int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]";
}

// Функция для вывода двумерного массива
void print2DArray(int arr[][17], int rows) {
    cout << "\nДвумерный массив " << rows << "x17:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < 17; j++) {
            printf("%4d ", arr[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Инициализация генератора случайных чисел
    srand(time(nullptr));
    
    const int ROWS = 9;
    const int COLS = 17;
    
    // Создание двумерного массива
    int matrix[ROWS][COLS];
    
    // Заполнение случайными числами от -50 до 50
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 101 - 50;  // числа от -50 до 50
        }
    }
    
    // Вывод исходного двумерного массива
    print2DArray(matrix, ROWS);
    
    cout << "================================================" << endl;
    cout << "РЕЗУЛЬТАТЫ РАБОТЫ ФУНКЦИЙ ДЛЯ КАЖДОЙ СТРОКИ" << endl;
    cout << "================================================" << endl;
    cout << "Формула: разность = (кол-во отрицательных) - (кол-во положительных)\n" << endl;
    
    // Демонстрация работы обеих функций для каждой строки
    for (int i = 0; i < ROWS; i++) {
        // СПОСОБ 1: Используем функцию с указателями
        // Передаем указатель на первый элемент строки (matrix[i] - это адрес начала i-й строки)
        int result_ptr = diffNegativePositive_ptr(matrix[i], COLS);
        
        // СПОСОБ 2: Используем обычную функцию
        // Передаем строку как одномерный массив
        int result_arr = diffNegativePositive_arr(matrix[i], COLS);
        
        // Вывод результатов
        cout << "Строка " << i + 1 << ": ";
        printArray(matrix[i], COLS);
        cout << endl;
        cout << "   Через указатели: разность = " << result_ptr << endl;
        cout << "   Обычным способом: разность = " << result_arr << endl;
        
        // Проверка, что результаты совпадают
        if (result_ptr == result_arr) {
            cout << "   ✓ Результаты совпадают" << endl;
        } else {
            cout << "   ✗ ОШИБКА: результаты не совпадают!" << endl;
        }
        cout << endl;
    }
    
    // Дополнительная демонстрация: работа с одномерным массивом
    cout << "\n================================================" << endl;
    cout << "ДЕМОНСТРАЦИЯ РАБОТЫ ФУНКЦИЙ С ОДНОМЕРНЫМ МАССИВОМ" << endl;
    cout << "================================================" << endl;
    
    const int testSize = 10;
    int testArray[testSize];
    
    cout << "Тестовый массив: ";
    for (int i = 0; i < testSize; i++) {
        testArray[i] = rand() % 21 - 10;  // числа от -10 до 10
        cout << testArray[i] << " ";
    }
    cout << endl;
    
    // Вызов первой функции (через указатели)
    cout << "\nСпособ 1 (через указатели):" << endl;
    cout << "Вызов: diffNegativePositive_ptr(testArray, " << testSize << ")" << endl;
    int result1 = diffNegativePositive_ptr(testArray, testSize);
    cout << "Результат: " << result1 << endl;
    
    // Вызов второй функции (обычным способом)
    cout << "\nСпособ 2 (обычный):" << endl;
    cout << "Вызов: diffNegativePositive_arr(testArray, " << testSize << ")" << endl;
    int result2 = diffNegativePositive_arr(testArray, testSize);
    cout << "Результат: " << result2 << endl;
    
    return 0;
}