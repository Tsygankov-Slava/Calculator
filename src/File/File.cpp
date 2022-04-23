#include "File.h"

map<string, string> File::getText() {
    string str, line;
    map<string, string> arr;
    ifstream file;
    if (file.is_open()) {
        cout << "File can't open.";
        exit(2);
    }
    file.open(File::path);
    while (getline(file, str)) {
        int index = 0;
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());

        std::string::iterator end_pos2 = std::remove(str.begin(), str.end(), '\r');
        str.erase(end_pos2, str.end());

        while (str[index] != '=') ++index;
        arr[str.substr(0, index)] = str.substr(index + 1, str.size());
    }
    return arr;
}