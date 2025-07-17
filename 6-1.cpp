#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int countEvenIndexOddNumbers(const vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if ((i + 1) % 2 == 0 && arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int findMaxEven(const vector<int>& arr) {
    int max_even = INT_MIN; 
    for (int num : arr) {
        if (num % 2 == 0 && num > max_even) {
            max_even = num;
        }
    }
    return (max_even != INT_MIN) ? max_even : -1; 
}

int main() {
    vector<int> arr = {3, 8, 5, 2, 7, 4, 9, 6, 11, 10};

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int count = countEvenIndexOddNumbers(arr);
    cout << "Количество элементов с четными порядковыми номерами, но нечетных по значению: " << count << endl;

    int max_even = findMaxEven(arr);
    if (max_even != -1) {
        cout << "Наибольшее четное значение в массиве: " << max_even << endl;
    } else {
        cout << "В массиве нет четных чисел" << endl;
    }

    return 0;
}