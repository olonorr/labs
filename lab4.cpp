#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Функция для заполнения массива случайными числами
void fillArray(int arr[], int size, int minVal = 0, int maxVal = 100) {
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// Функция для вывода массива
void printArray(const int arr[], int size, const string& title = "") {
    if (!title.empty()) {
        cout << title << endl;
    }
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

// Сортировка "пузырьком" для участка массива (по убыванию)
void bubbleSortDesc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортировка "пузырьком" для участка массива (по возрастанию)
void bubbleSortAsc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        for (int j = start; j < end - 1 - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортировка прямым выбором для участка массива (по убыванию)
void selectionSortDesc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

// Сортировка прямым выбором для участка массива (по возрастанию)
void selectionSortAsc(int arr[], int start, int end) {
    for (int i = start; i < end - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < end; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    
    const int SIZE = 28;
    int X[SIZE];
    
    // Заполнение массива случайными числами
    fillArray(X, SIZE, 10, 99);
    
    cout << "========================================" << endl;
    cout << "Исходный массив X[28]:" << endl;
    cout << "========================================" << endl;
    printArray(X, SIZE);
    
    // Копия массива для двух методов сортировки
    int X_bubble[SIZE];
    int X_selection[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        X_bubble[i] = X[i];
        X_selection[i] = X[i];
    }
    
    // Сортировка пузырьком
    cout << "\n========================================" << endl;
    cout << "СОРТИРОВКА МЕТОДОМ 'ПУЗЫРЬКА':" << endl;
    cout << "========================================" << endl;
    
    bubbleSortDesc(X_bubble, 8, 18);
    bubbleSortAsc(X_bubble, 18, SIZE);
    
    cout << "Массив после сортировки 'пузырьком':" << endl;
    printArray(X_bubble, SIZE);
    
    // Сортировка методом прямого выбора
    cout << "\n========================================" << endl;
    cout << "СОРТИРОВКА МЕТОДОМ ПРЯМОГО ВЫБОРА:" << endl;
    cout << "========================================" << endl;
    
    selectionSortDesc(X_selection, 8, 18);
    selectionSortAsc(X_selection, 18, SIZE);
    
    cout << "Массив после сортировки прямым выбором:" << endl;
    printArray(X_selection, SIZE);
    
    // Проверка корректности сортировки
    cout << "\n========================================" << endl;
    cout << "ПРОВЕРКА РЕЗУЛЬТАТОВ:" << endl;
    cout << "========================================" << endl;
    
    cout << "Первые 8 элементов (не трогали): ";
    for (int i = 0; i < 8; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
    
    cout << "Элементы 8-17 (по убыванию): ";
    for (int i = 8; i < 18; i++) {
        cout << X_bubble[i] << " ";
        if (i > 8 && X_bubble[i] > X_bubble[i-1]) {
            cout << "\nОШИБКА: массив не отсортирован по убыванию!";
            break;
        }
    }
    cout << endl;
    
    cout << "Элементы 18-27 (по возрастанию): ";
    for (int i = 18; i < SIZE; i++) {
        cout << X_bubble[i] << " ";
        if (i > 18 && X_bubble[i] < X_bubble[i-1]) {
            cout << "\nОШИБКА: массив не отсортирован по возрастанию!";
            break;
        }
    }
    cout << endl;
    
    cout << "\nПрограмма завершена успешно!" << endl;
    
    return 0;
}