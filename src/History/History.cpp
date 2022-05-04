#include "History.h"

void History::inHistory(std::string &path, std::string text) {
    std::ofstream file;
    file.open(path, std::ios::app);
    file << text + "\n";
    file.close();
}

void History::outHistory(std::string &path) {
    std::ifstream file;
    file.open(path, std::ios::in);

    std::cout << "|--------------\n";
    std::string line;
    bool flag = true;
    while (getline(file, line)) {
        if (line != "") {
            std::cout << "|" << line << "\n";
            flag = false;
        }
    }
    if (flag) {
        std::cout << "| Нет данных о вычислениях\n";
    }
    std::cout << "|--------------\n";
    file.close();
}

void History::clearHistory(std::string &path) {
    std::ofstream file;
    file.open(path, std::ios::trunc);
    file.close();
}