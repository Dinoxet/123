#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double calculateY(double x) {
    if (fabs(x) < 3) {
        return (2 * pow(x, 3)) / (pow(x, 2) + 1);
    } else {
        return 1.5 * tan(M_PI) / x;
    }
}

int main() {
    cout << "Таблица значений функции y(x):\n";
    cout << "-----------------------------\n";
    cout << "    x    |    y(x)\n";
    cout << "-----------------------------\n";
    
    cout << fixed << setprecision(4);
    
    for (double x = -6.0; x <= 6.0; x += 0.5) {
        double y = calculateY(x);
        
        cout << setw(8) << x << " |" << setw(10) << y << endl;
    }
    
    return 0;
}