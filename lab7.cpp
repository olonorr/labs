#include <iostream>
#include <windows.h>
#include <cmath>

const double PI = acos(-1.0);

void calculateCylinderProperties(double radius, double height, 
                                  double &surface_area, 
                                  double &volume,
                                  double &lateral_surface_area,
                                  double &base_area) {
    if (radius < 0 || height < 0) {
        surface_area = 0;
        volume = 0;
        lateral_surface_area = 0;
        base_area = 0;
        std::cerr << "Ошибка: Радиус и высота не могут быть отрицательными!" << std::endl;
        return;
    }
    
    // Площадь основания
    base_area = PI * radius * radius;
    
    // Площадь боковой поверхности
    lateral_surface_area = 2 * PI * radius * height;
    
    // Полная площадь поверхности (два основания + боковая поверхность)
    surface_area = 2 * base_area + lateral_surface_area;
    
    // Объем цилиндра
    volume = base_area * height;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    double radius, height;
    double surface_area, volume, lateral_surface_area, base_area;
    
    std::cout << "Вычисление параметров цилиндра" << std::endl;
    std::cout << "Введите радиус цилиндра: ";
    std::cin >> radius;
    std::cout << "Введите высоту цилиндра: ";
    std::cin >> height;
    
    calculateCylinderProperties(radius, height, 
                                surface_area, volume, 
                                lateral_surface_area, base_area);
    
    std::cout << "\nРезультаты" << std::endl;
    std::cout << "Радиус: " << radius << std::endl;
    std::cout << "Высота: " << height << std::endl;
    std::cout << "Площадь основания: " << base_area << std::endl;
    std::cout << "Площадь боковой поверхности: " << lateral_surface_area << std::endl;
    std::cout << "Полная площадь поверхности: " << surface_area << std::endl;
    std::cout << "Объем цилиндра: " << volume << std::endl;
    
    // Вычисление с другими значениями
    std::cout << "\nДополнительная демонстрация" << std::endl;
    
    double test_radius = 5.0;
    double test_height = 10.0;
    double test_surface, test_volume, test_lateral, test_base;
    
    calculateCylinderProperties(test_radius, test_height, 
                                test_surface, test_volume, 
                                test_lateral, test_base);
    
    std::cout << "Для цилиндра с радиусом " << test_radius 
              << " и высотой " << test_height << ":" << std::endl;
    std::cout << "Полная площадь поверхности = " << test_surface << std::endl;
    std::cout << "Объем = " << test_volume << std::endl;
    
    return 0;
}