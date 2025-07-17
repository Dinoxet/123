#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream> // Добавлен этот заголовочный файл

using namespace std;

struct ProductData {
    string name;
    vector<int> monthlySales;
    vector<int> cumulativeSales;
    int maxSalesMonth;
};

void calculateCumulative(vector<ProductData>& products) {
    for (auto& product : products) {
        product.cumulativeSales.clear();
        int sum = 0;
        for (int sales : product.monthlySales) {
            sum += sales;
            product.cumulativeSales.push_back(sum);
        }
    }
}

void findMaxSalesMonth(vector<ProductData>& products) {
    for (auto& product : products) {
        auto max_it = max_element(product.monthlySales.begin(), product.monthlySales.end());
        product.maxSalesMonth = distance(product.monthlySales.begin(), max_it) + 1;
    }
}

vector<ProductData> readDataFromFile(const string& filename) {
    ifstream fin(filename);
    vector<ProductData> products;

    if (!fin.is_open()) {
        cerr << "Ошибка открытия файла " << filename << endl;
        return products;
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        ProductData product;
        iss >> product.name;

        int sale;
        while (iss >> sale) {
            product.monthlySales.push_back(sale);
        }

        products.push_back(product);
    }

    fin.close();
    return products;
}

void writeResultsToFile(const string& filename, const vector<ProductData>& products) {
    ofstream fout(filename);

    if (!fout.is_open()) {
        cerr << "Ошибка открытия файла " << filename << " для записи" << endl;
        return;
    }

    fout << "Результаты анализа сбыта продукции за год:\n\n";
    for (const auto& product : products) {
        fout << "Продукция: " << product.name << "\n";
        fout << "Накопительные итоги по месяцам: ";
        for (int sum : product.cumulativeSales) {
            fout << sum << " ";
        }
        fout << "\nМесяц с максимальным сбытом: " << product.maxSalesMonth << "\n\n";
    }

    fout.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const string inputFile = "sales_data.txt";
    const string outputFile = "sales_results.txt";

    vector<ProductData> products = readDataFromFile(inputFile);

    if (products.empty()) {
        cout << "Не удалось прочитать данные или файл пуст." << endl;
        return 1;
    }

    calculateCumulative(products);
    findMaxSalesMonth(products);
    writeResultsToFile(outputFile, products);

    cout << "Анализ завершен. Результаты сохранены в файл " << outputFile << endl;

    return 0;
}