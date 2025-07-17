#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inputArray() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

void printArray(const vector<int>& arr) {
    cout << "Массив: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> removeDuplicates(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    auto last = unique(arr.begin(), arr.end());
    
    arr.erase(last, arr.end());
    
    return arr;
}

int main() {
    vector<int> arr = inputArray();
    
    cout << "\nИсходный ";
    printArray(arr);
    
    vector<int> uniqueArr = removeDuplicates(arr);
    
    cout << "Массив без повторений ";
    printArray(uniqueArr);
    
    return 0;
}