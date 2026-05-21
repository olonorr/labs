#include <iostream>
#include <windows.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double a, z1, z2;
    const double PI = acos(-1.0);
    

    cout << "Введите значение a: ";
    cin >> a;
    
    double arg1 = 3 * PI - 2 * a;
    double arg2 = 5 * PI + 2 * a;
    z1 = pow(sin(arg1), 2) * pow(cos(arg2), 2);
    
    double arg3 = (5.0/2.0) * PI - 8 * a;
    z2 = 1.0/8.0 - (1.0/8.0) * sin(arg3);
    
    cout << fixed << setprecision(6);
    cout << "\nРезультаты вычислений:" << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
    
    // Проверка равенства формул (с учётом погрешности вычислений)
    const double EPS = 1e-10;
    if (fabs(z1 - z2) < EPS) {
        cout << "\nФормулы равны" << endl;
    } else {
        cout << "\nФормулы не равны. Разница: " << fabs(z1 - z2) << endl;
    }
    
    return 0;
}