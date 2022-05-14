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

    std::cout << "\tИстория вычислений: \n";

    std::string line;
    bool flag = true;
    while (getline(file, line)) {
        if (line != "") {
            std::cout << "\t\t" << line << "\n";
            flag = false;
        }
    }
    if (flag) {
        std::cout << "\t\tНет данных о вычислениях\n";
    }
    file.close();
}

void History::clearHistory(std::string &path) {
    std::cout << "\t История вычислений очищена!\n";
    std::ofstream file;
    file.open(path, std::ios::trunc);
    file.close();
}