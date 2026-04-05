#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> // для std::remove_if
int main() {
    std::string st;
    std::getline(std::cin, st);
    std::istringstream iss(st);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    // Проверка на пустой ввод
    if (words.empty()) {
        std::cout << "No words entered.\n";
        return 0;
    }
    int sumlens = 0;
    for (size_t i = 0; i < words.size(); i++) {
        sumlens += words[i].length();
    }
    sumlens = sumlens / words.size(); // Средняя длина слова
    // Безопасное удаление слов длиной <= sumlens
    words.erase(
        std::remove_if(words.begin(), words.end(),
            [sumlens](const std::string& w) { return w.size() <= sumlens; }),
        words.end()
    );
    // Вывод оставшихся слов
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    return 0;
}
