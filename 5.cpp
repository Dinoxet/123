#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Логическая функция, проверяющая принадлежность точки единичной окружности
bool Yes(double x, double y) {
    // Уравнение единичной окружности: x² + y² = 1
    return fabs(x*x + y*y - 1) < 1e-6; // С учетом погрешности вычислений
}

int main() {
    cout << "Проверка точек параболы y = x² на принадлежность единичной окружности:\n";
    cout << "+------+------+----------------+\n";
    cout << "|   x  |   y  | Принадлежит?  |\n";
    cout << "+------+------+----------------+\n";

    for (double x = -2.0; x <= 2.0; x += 0.5) {
        double y = x * x;
        bool belongs = Yes(x, y);
        
        cout << "| " << setw(5) << x << " | " << setw(5) << y << " | " 
             << setw(14) << (belongs ? "Да" : "Нет") << " |\n";
    }

    cout << "+------+------+----------------+\n";
    return 0;
}