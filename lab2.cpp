#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

/////////////////////////////////
// -1 <= x <= 2 AND
// -1 <= y <= 2 AND
// x <= 0 or >= 1

bool isPointInFigure(double x, double y) {
    if (x > 2 || y > 2 || y < -1 || x < -1) return false;
    if (x > 0 && y < 1) return false;
    return true;
}

bool isPointInFigureAlt(double x, double y) {
    bool inMainArea = (x >= -1 && x <= 2 && y >= -1 && y <= 2);
    
    if (!inMainArea) return false;
    
    if (x > 0 && y < 1) {
        if (x*x + (y-0.5)*(y-0.5) < 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double x = 0;
    double y = 0;

    cout << "Введите координату X: ";
    cin >> x;
    cout << "Введите координату Y: ";
    cin >> y;
    if (isPointInFigure(x, y)) {
        cout << "точка (" << x << "," << y << ") попала в мишень";
        return 0;
    }
    cout << "точка (" << x << "," << y << ") HE попала в мишень";

    return 0;
}