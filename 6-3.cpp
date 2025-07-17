#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateRandomArray(int* arr, int size, int minVal, int maxVal) {
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

int* filterSpecialElements(int* source, int size, int& newSize) {
    newSize = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0 && source[i] % 2 != 0) {
            newSize++;
        }
    }
    
    int* result = new int[newSize];
    
    int index = 0;
    for (int i = 0; i < size; i++) {
        if ((i + 1) % 2 == 0 && source[i] % 2 != 0) {
            result[index++] = source[i];
        }
    }
    
    return result;
}

void printArray(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    generateRandomArray(arr, SIZE, 1, 50);
    cout << "Сгенерированный массив: ";
    printArray(arr, SIZE);
    
    int filteredSize;
    int* filteredArr = filterSpecialElements(arr, SIZE, filteredSize);
    
    cout << "Элементы с четными порядковыми номерами, но нечетные по значению: ";
    printArray(filteredArr, filteredSize);
    
    delete[] filteredArr;
    
    return 0;
}