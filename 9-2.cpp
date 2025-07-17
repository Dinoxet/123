#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string removeWord(const string& str, int M) {
    istringstream iss(str);
    vector<string> words;
    string word;
    
    while (iss >> word) {
        words.push_back(word);
    }
    
    if (M < 1 || M > words.size()) {
        return str; 
    }
    
    words.erase(words.begin() + M - 1);
    
    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) oss << " ";
        oss << words[i];
    }
    
    return oss.str();
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fin("F1.txt");
    ofstream fout("F2.txt");
    
    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла F1.txt" << endl;
        return 1;
    }
    
    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла F2.txt" << endl;
        return 1;
    }
    
    int M;
    cout << "Введите номер слова для удаления (начиная с 1): ";
    cin >> M;
    
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            string newLine = removeWord(line, M);
            fout << newLine << endl;
        }
    }
    
    fin.close();
    fout.close();
    
    cout << "Обработка завершена. Результат записан в F2.txt" << endl;
    
    return 0;
}