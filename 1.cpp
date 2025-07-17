#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    cout << "Введите длины катетов: ";
    cin >> a >> b;

    double c = sqrt(a*a + b*b);
    
    double perimeter = a + b + c;
    double area = (a * b) / 2;
    
    cout << fixed << setprecision(2);
    cout << "Периметр: " << perimeter << endl;
    cout << "Площадь: " << area << endl;
    
    return 0;
}