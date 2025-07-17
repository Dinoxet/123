#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const double MAX_DEVIATION = 0.03; 

bool isDefective(double bottom, double center, double top) {
    double conicity = abs(top - bottom) / bottom;
    
    double average = (bottom + top) / 2.0;
    double barrelness = abs(center - average) / average;
    
    return (conicity > MAX_DEVIATION) || (barrelness > MAX_DEVIATION);
}

int main() {
    int n;
    cin >> n;
    
    vector<double> bottomDiameters(n);
    vector<double> centerDiameters(n);
    vector<double> topDiameters(n);
    vector<bool> isDefectiveList(n, false);
    
    for (int i = 0; i < n; i++) {
        cin >> bottomDiameters[i] >> centerDiameters[i] >> topDiameters[i];
    }
    
    int defectiveCount = 0;
    for (int i = 0; i < n; i++) {
        if (isDefective(bottomDiameters[i], centerDiameters[i], topDiameters[i])) {
            isDefectiveList[i] = true;
            defectiveCount++;
        }
    }
    
    cout << fixed << setprecision(3);
    cout << "\nРезультаты проверки:\n";
    cout << "-------------------------------------------------\n";
    cout << "| Деталь | Нижний | Центр. | Верхний | Брак     |\n";
    cout << "-------------------------------------------------\n";
    
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(6) << i+1 << " | " 
             << setw(6) << bottomDiameters[i] << " | "
             << setw(6) << centerDiameters[i] << " | "
             << setw(7) << topDiameters[i] << " | "
             << setw(8) << (isDefectiveList[i] ? "Да" : "Нет") << " |\n";
    }
    cout << "-------------------------------------------------\n";
    
    double defectivePercent = (static_cast<double>(defectiveCount) / n) * 100;
    cout << "\nПроцент бракованных деталей: " << setprecision(1) << defectivePercent << "%\n";
    
    return 0;
}