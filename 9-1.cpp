#include <iostream>
#include <string>
#include <cctype> 

int countPunctuationMarks(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (ispunct(c)) { 
            count++;
        }
    }
    return count;
}

int main() {
    std::string text = "Привет, мир! Как дела? Хорошо...";
    int punctuationCount = countPunctuationMarks(text);
    
    std::cout << "Строка: \"" << text << "\"" << std::endl;
    std::cout << "Количество знаков препинания: " << punctuationCount << std::endl;
    
    return 0;
}