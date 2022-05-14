#include "Command.h"

bool Command::isCommand(std::string &str, Variables &var, File &file, History &history) {
    if (str == "help()") {
        std::cout << "\tСправочная информация: \n";
        std::cout << "\t\tВводить выражение надо после >>>\n";
        std::cout << "\t\tОтвет выводится после -->\n\n";
        std::cout << "\t Команды:\n";
        std::cout << "\t\thelp()           : Выведет справочную информацию и подскажет всевозможные команды\n";
        std::cout << "\t\tvars()           : Выведет файл с переменными\n";
        std::cout << "\t\tvars(var)        : Выведет значение переменной var, можно через запятую [var1,var2]\n";
        std::cout << "\t\tdelete_var(all)  : Удалит весь файл с переменными\n";
        std::cout << "\t\tdelete_var(var)  : Удалит переменную из var из файла, можно через запятую [var1,var2]\n";
        std::cout << "\t\thistory()        : Выведет историю вычислений выражений\n";
        std::cout << "\t\tdelete_history() : Удалит историю вычислений выражений\n";
        std::cout << "\t\texit()           : Завершит работу калькулятора\n";
        return true;
    } else {
        std::string cmd1 = str.substr(0, str.find('(')+1);
        std::string cmd2 = str.substr(str.find('(') + 1, str.size() - str.find('(') - 2);
        if (cmd1 == "vars(") {
            outVariables(var.variableAndMeaning, cmd2);
            return true;
        } else if (cmd1 == "delete_var(") {
            delVariables(var, cmd2, file);
            return true;
        } else if (cmd1 + ')' == "history()") {
            history.outHistory(file.pathHistory);
            return true;
        } else if (cmd1 + ')' == "delete_history()") {
            history.clearHistory(file.pathHistory);
            return true;
        }
    }
    return false;
}

void Command::outVariables(std::map<std::string, std::string> &variableAndMeaning, std::string var) {
    if (!variableAndMeaning.empty()) {
        if (var.empty()) {
            std::cout << "\tКол-во переменных в файле -> " << variableAndMeaning.size() << "\n";
            std::cout << "\tПеременные из файла: \n";
            for (auto &i : variableAndMeaning) {
                std::cout << "\t\t" << i.first << " = " << i.second << "\n";
            }
        } else {
            Vector arrVar = getVariables(var);
            for (int i = 0; i < arrVar.index; i++) {
                std::string v = arrVar.arrString[i];
                if (variableAndMeaning.count(v)) {
                    std::cout << "\t\t" << v << " = " << variableAndMeaning[v] << "\n";
                } else {
                    std::cout << "\t\tWarning: Переменная " << v << " не найдена!\n";
                }
            }
        }
    } else {
        std::cout << "\tНе обнаружено переменных в файле!\n";
    }
}

void Command::delVariables(Variables &var, std::string &v, File &file) {
    if (!var.variableAndMeaning.empty()) {
        std::ofstream f;
        if (v == "all") {
            f.open(file.pathVariables, std::ios_base::trunc);
            var.variableAndMeaning.clear();
            var.variables.index = 0;
            var.variables.size = 100;
            delete[] var.variables.arrString;
            std::cout << "\tФайл успешно очищен!\n";
            f.close();
        } else {
            Vector arrVar = getVariables(v);
            for (int i = 0; i < arrVar.index; ++i) {
                std::string variable = arrVar.arrString[i];
                if (var.variableAndMeaning.count(variable)) {
                    deleteVarInFile(file, variable);
                    var.variableAndMeaning.erase(var.variableAndMeaning.find(variable));
                    var.variables.arrString = var.variables.delElement(var.variables, variable);
                    std::cout << "\tПеременная " << variable << " успешно удалена из файла!\n";
                } else {
                    std::cout << "\tWarning: Переменная " << variable << " не найдена!\n\tУдаление не произошло!\n";
                }
            }
        }
    } else {
        std::cout << "\tФайл и так пуст!\n";
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
    std::ifstream f(file.pathVariables);
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
    std::ofstream fOut(file.pathVariables);
    fOut << text;
}