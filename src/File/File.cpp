#include "File.h"

std::map<std::string, std::string> File::getText() {
    std::string str, line;
    std::map<std::string, std::string> arr;
    std::ifstream file(pathVariables);

    if (file) {
        while (getline(file, str)) {
            if (!str.empty()) {
                int index = 0;
                std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
                str.erase(end_pos, str.end());

                std::string::iterator end_pos2 = std::remove(str.begin(), str.end(), '\n');
                str.erase(end_pos2, str.end());

                std::string::iterator end_pos3 = std::remove(str.begin(), str.end(), '\r');
                str.erase(end_pos3, str.end());

                while (str[index] != '=') ++index;
                arr[str.substr(0, index)] = str.substr(index + 1, str.size());
            }
        }
    }
    return arr;
}

void File::checkFileVariablesAccess(Variables &var) {
    if (pathVariables != " ") {
        var.variableAndMeaning = getText();
    } else {
        std::cout << "Warning: Нет доступа к файлу с переменными\n";
    }
}

void File::addVariable(std::string &str) {
    std::ofstream file;
    file.open(pathVariables, std::ios::app);
    file << "\n" + str;
    file.close();
    std::cout << "Переменная успешно добавлена!\n";
}

bool File::checkFileHistoryAccess() {
    return (pathHistory != " ");
}