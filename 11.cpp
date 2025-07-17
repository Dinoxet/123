#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

struct PassengerLuggage {
    int itemCount;
    double totalWeight;
};

vector<PassengerLuggage> inputLuggageData() {
    vector<PassengerLuggage> luggageList;
    int n;

    cout << "Введите количество пассажиров: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        PassengerLuggage luggage;
        cout << "Пассажир " << i + 1 << ":\n";
        cout << "  Количество вещей: ";
        cin >> luggage.itemCount;
        cout << "  Общий вес вещей: ";
        cin >> luggage.totalWeight;

        luggageList.push_back(luggage);
    }

    return luggageList;
}

void outputLuggageData(const vector<PassengerLuggage>& luggageList) {
    cout << "\nИнформация о багаже пассажиров:\n";
    cout << "--------------------------------\n";
    for (size_t i = 0; i < luggageList.size(); ++i) {
        cout << "Пассажир " << i + 1 << ":\n";
        cout << "  Количество вещей: " << luggageList[i].itemCount << "\n";
        cout << "  Общий вес вещей: " << luggageList[i].totalWeight << "\n";
        cout << "--------------------------------\n";
    }
}

int countPassengersWithMaxTwoItems(const vector<PassengerLuggage>& luggageList) {
    int count = 0;
    for (const auto& luggage : luggageList) {
        if (luggage.itemCount <= 2) {
            count++;
        }
    }
    return count;
}

int countPassengersAboveAverage(const vector<PassengerLuggage>& luggageList) {
    if (luggageList.empty()) return 0;

    int totalItems = 0;
    for (const auto& luggage : luggageList) {
        totalItems += luggage.itemCount;
    }
    double averageItems = static_cast<double>(totalItems) / luggageList.size();

    int count = 0;
    for (const auto& luggage : luggageList) {
        if (luggage.itemCount > averageItems) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<PassengerLuggage> luggageList = inputLuggageData();

    outputLuggageData(luggageList);

    int passengersWithMaxTwoItems = countPassengersWithMaxTwoItems(luggageList);
    cout << "\nКоличество пассажиров с не более чем двумя вещами: "
        << passengersWithMaxTwoItems << endl;

    int passengersAboveAverage = countPassengersAboveAverage(luggageList);
    cout << "Количество пассажиров с числом вещей больше среднего: "
        << passengersAboveAverage << endl;

    return 0;
}