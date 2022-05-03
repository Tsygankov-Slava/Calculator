#include "Command.h"

bool Command::isCommand(std::string &str, Variables &var, File &file) {
    if (str == "-help") {
        std::cout << "|------------------------------------------------------------------------------|\n";
        std::cout << "| -help -> Подскажет всевозможные команды                                      |\n";
        std::cout << "| -out all -> Выведет файл с переменными                                       |\n";
        std::cout << "| -out var -> Выведет значение переменной var, можно через запятую [var1,var2] |\n";
        std::cout << "| -del all -> Удалит весь файл с переменными                                   |\n";
        std::cout << "| -del var -> Удалит переменную из файла                                       |\n";
        std::cout << "| -exit -> Завершит работу калькулятора                                        |\n";
        std::cout << "|------------------------------------------------------------------------------|\n\n";
        return true;
    } else {
        std::string cmd1 = str.substr(0, str.find(' '));
        std::string cmd2 = str.substr(str.find(' ') + 1, str.size());
        if (cmd1 == "-out") {
            outVariables(var.variableAndMeaning, cmd2);
            return true;
        } else if (cmd1 == "-del") {
            delVariables(var, cmd2, file);
            return true;
        }
    }
    return false;
}

void Command::outVariables(std::map<std::string, std::string> &variableAndMeaning, std::string var) {
    if (!variableAndMeaning.empty()) {
        if (var == "all") {
            std::cout << "Переменные из файла: \n";
            std::cout << "Кол-во переменных -> " << variableAndMeaning.size() << "\n";
            std::cout << "|---------\n";
            for (auto &i : variableAndMeaning) {
                std::cout << "|" << i.first << " = " << i.second << "\n";
            }
            std::cout << "|---------\n";
        } else {
            Vector arrVar = getVariables(var);
            for (int i = 0; i < arrVar.index; i++) {
                std::string v = arrVar.arrString[i];
                if (variableAndMeaning.count(v)) {
                    std::cout << "|" << v << " = " << variableAndMeaning[v] << "\n";
                } else {
                    std::cout << "Warning: Переменная " << v << " не найдена!\n";
                }
            }
        }
    } else {
        std::cout << "Не обнаружено переменных в файле!\n";
    }
}

void Command::delVariables(Variables &var, std::string &v, File &file) {
    if (!var.variableAndMeaning.empty()) {
        std::ofstream f;
        if (v == "all") {
            f.open(file.path, std::ios_base::trunc);
            var.variableAndMeaning.clear();
            var.variables.index = 0;
            var.variables.size = 100;
            delete[] var.variables.arrString;
            std::cout << "Файл успешно очищен!\n";
            f.close();
        } else {
            Vector arrVar = getVariables(v);
            for (int i = 0; i < arrVar.index; ++i) {
                std::string variable = arrVar.arrString[i];
                if (var.variableAndMeaning.count(variable)) {
                    deleteVarInFile(file, variable);
                    var.variableAndMeaning.erase(var.variableAndMeaning.find(variable));
                    var.variables.arrString = var.variables.delElement(var.variables, variable);
                    std::cout << "Переменная " << variable << " успешно удалена из файла!\n";
                } else {
                    std::cout << "Warning: Переменная " << variable << " не найдена!\nУдаление не произошло!\n";
                }
            }
        }
    } else {
        std::cout << "Файл и так пуст!\n";
    }
}

Vector Command::getVariables(std::string &str) {
    Vector arrVar;
    std::string var;
    for (int i = 0; i < str.size() + 1; ++i) {
        if (str[i] == ',' || i == str.size()) {
            arrVar.push_back(var);
            var = "";
        } else if (str[i] != ' ') {
            var += str[i];
        }
    }
    return arrVar;
}

void Command::deleteVarInFile(File file, std::string var) {
    std::string text, line, strVar;
    std::ifstream f(file.path);
    while (getline(f, line)) {
        strVar = "";
        int i = 0;
        while (line[i] != '=') {
            if (line[i] != ' ') {
                strVar += line[i];
            }
            ++i;
        }
        if (var != strVar) {
            text += line + "\n";
        }
    }
    std::ofstream fOut(file.path);
    fOut << text;
}