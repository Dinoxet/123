#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

void solveSystem() {
    double a1, b1, c1, a2, b2, c2;
    
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    
    double D = a1 * b2 - a2 * b1;
    double Dx = c1 * b2 - c2 * b1;
    double Dy = a1 * c2 - a2 * c1;
    
    cout << "\nСистема уравнений:\n";
    cout << fixed << setprecision(2);
    cout << a1 << "x + " << b1 << "y = " << c1 << endl;
    cout << a2 << "x + " << b2 << "y = " << c2 << endl;
    
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "\nРешение:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "\nСистема имеет бесконечное множество решений\n";
        } else {
            cout << "\nСистема не имеет решений\n";
        }
    }
}

int main() {
    char choice;
    
    do {
        solveSystem();
        
        cout << "\nХотите решить еще одну систему? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (tolower(choice) == 'y');
    
    return 0;
}