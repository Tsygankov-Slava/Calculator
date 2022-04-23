#include "Debug.h"

void Debug::printSourceExpressions(){
    cout << "\n--Исходные выражения--\n";
    for (auto i : var.variableAndMeaning) cout << i.first << "=" << i.second << "\n";
    cout << "----\n\n";
};
void Debug::printAllVariables(){

};
void Debug::printExpressionsAfterReplacement(){

};