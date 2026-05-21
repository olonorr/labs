#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

const int MATRIX_SIZE = 7;

// Функция для ввода матрицы с клавиатуры
void inputMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    cout << "Введите элементы матрицы " << MATRIX_SIZE << "x" << MATRIX_SIZE << ":" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Функция для заполнения матрицы случайными числами
void randomMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 201 - 100; // Случайные числа от -100 до 100
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const int matrix[MATRIX_SIZE][MATRIX_SIZE], const string& title) {
    cout << "\n" << title << ":" << endl;
    cout << "     ";
    for (int j = 0; j < MATRIX_SIZE; j++) {
        cout << setw(5) << "Col" << j;
    }
    cout << endl;
    cout << "     ";
    for (int j = 0; j < MATRIX_SIZE; j++) {
        cout << setw(5) << "-----";
    }
    cout << endl;
    
    for (int i = 0; i < MATRIX_SIZE; i++) {
        cout << "Row" << setw(2) << i << " ";
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Функция для определения суммы отрицательных элементов в каждом столбце
void sumNegativeInColumns(const int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    cout << "\nСумма отрицательных элементов в каждом столбце:" << endl;
    for (int j = 0; j < MATRIX_SIZE; j++) {
        int sum = 0;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            if (matrix[i][j] < 0) {
                sum += matrix[i][j];
            }
        }
        cout << "Столбец " << j << ": " << sum << endl;
    }
}

// Функция для поиска местоположения максимального элемента
void findMaxElement(const int matrix[MATRIX_SIZE][MATRIX_SIZE], int& maxRow, int& maxCol) {
    int maxValue = INT_MIN;
    maxRow = 0;
    maxCol = 0;
    
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    
    cout << "\nМаксимальный элемент матрицы: " << maxValue << endl;
    cout << "Его местоположение: строка " << maxRow << ", столбец " << maxCol << endl;
}

// Функция для замены элементов побочной диагонали нулями
void replaceSecondaryDiagonal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix[i][MATRIX_SIZE - 1 - i] = 0;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    
    int matrix[MATRIX_SIZE][MATRIX_SIZE];
    int choice;
    
    cout << "Программа для работы с матрицей " << MATRIX_SIZE << "x" << MATRIX_SIZE << endl;
    cout << "Выберите способ заполнения матрицы:" << endl;
    cout << "1 - Ввод с клавиатуры" << endl;
    cout << "2 - Случайное заполнение" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            inputMatrix(matrix);
            break;
        case 2:
            randomMatrix(matrix);
            break;
        default:
            cout << "Неверный выбор. Используется случайное заполнение." << endl;
            randomMatrix(matrix);
    }
    
    // Выводим исходную матрицу
    printMatrix(matrix, "Исходная матрица");
    
    // Определяем сумму отрицательных элементов в каждом столбце
    sumNegativeInColumns(matrix);
    
    // Находим местоположение максимального элемента
    int maxRow, maxCol;
    findMaxElement(matrix, maxRow, maxCol);
    
    // Заменяем элементы побочной диагонали нулями
    replaceSecondaryDiagonal(matrix);
    
    // Выводим измененную матрицу
    printMatrix(matrix, "Измененная матрица (побочная диагональ заменена нулями)");
    
    return 0;
}