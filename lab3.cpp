#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPointInFigure(double x, double y) {
    if (x > 2 || y > 2 || y < -1 || x < -1) return false;
    if (x > 0 && y < 1) return false;
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    
    char choice;
    int totalShots = 0;
    int hits = 0;
    double x = 0;
    double y = 0;
    
    do {
        cout << "Введите координату X: ";
        cin >> x;
        cout << "Введите координату Y: ";
        cin >> y;
        
        cout << "Выстрел №" << (totalShots + 1) << endl;
        
        
        totalShots++;
        if (isPointInFigure(x, y)) {
            cout << "точка (" << x << "," << y << ") попала в мишень";
            hits++;
        } else {
            cout << "точка (" << x << "," << y << ") HE попала в мишень";
        }
        
        cout << endl;
        cout << "Продолжить ? (y/n): ";
        cin >> choice;
        cout << endl;
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Всего выстрелов: " << totalShots << endl;
    cout << "Попаданий: " << hits << endl;
    cout << "Промахов: " << (totalShots - hits) << endl;
    
    if (totalShots > 0) {
        double percent = (double)hits / totalShots * 100;
        cout << "Процент попаданий: " << percent << "%" << endl;
    }
    
    return 0;
}