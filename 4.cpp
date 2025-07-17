#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int day = 1;
    int daily_production = 2;  
    int total_production = 0;
    bool reached_max = false;

    cout << "+------+------------+---------------+\n";
    cout << "| День | Пар в день | Всего пар     |\n";
    cout << "+------+------------+---------------+\n";

    while (!reached_max) {
        total_production += daily_production;

        cout << "| " << setw(4) << day << " | " 
             << setw(10) << daily_production << " | " 
             << setw(13) << total_production << " |\n";

        if (daily_production >= 100) {
            reached_max = true;
        } else {
            daily_production *= 2;
            if (daily_production > 100) {
                daily_production = 100;
            }
            day++;
        }
    }

    cout << "+------+------------+---------------+\n\n";
    cout << "Вершина мастерства достигнута на " << day << " день\n";
    cout << "Всего сшито пар рукавиц: " << total_production << endl;

    return 0;
}