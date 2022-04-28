#include "File.h"

std::map<std::string, std::string> File::getText() {
    std::string str, line;
    std::map<std::string, std::string> arr;
    std::ifstream file;
    if (file.is_open()) {
        return arr;
    }
    file.open(File::path);
    while (getline(file, str)) {
        int index = 0;
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' '); // Написать функцию удаления символа из строки
        str.erase(end_pos, str.end());

        std::string::iterator end_pos2 = std::remove(str.begin(), str.end(), '\r');
        str.erase(end_pos2, str.end());

        while (str[index] != '=') ++index;
        arr[str.substr(0, index)] = str.substr(index + 1, str.size());
    }
    return arr;
}