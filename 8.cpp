#include <iostream>
#include <iomanip>
using namespace std;

void swapRows(int* &row1, int* &row2) {
    int* temp = row1;
    row1 = row2;
    row2 = temp;
}

void bubbleSortMatrix(int** matrix, int n, int m) {
    int swaps = 0;
    bool swapped;
    
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (matrix[i][0] > matrix[i + 1][0]) {
                swapRows(matrix[i], matrix[i + 1]);
                swaps++;
                swapped = true;
            }
        }
    } while (swapped);
    
    cout << "Количество перестановок: " << swaps << endl;
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nИсходная матрица:" << endl;
    printMatrix(matrix, n, m);
    
    bubbleSortMatrix(matrix, n, m);
    
    cout << "\nОтсортированная матрица:" << endl;
    printMatrix(matrix, n, m);
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}