#include "Arguments.h"

void Arguments::checkArguments(int argc, char *argv[], std::string &exp, File &file) {
    for (int i = 0; i < argc; ++i) {
        if (std::strcmp(argv[i], "-d") == 0) {
            isDebug = true;
        } else if (std::strcmp(argv[i], "--variables") == 0) {
            file.pathVariables = argv[i + 1];
        } else if (std::strcmp(argv[i], "--exp") == 0) {
            exp = argv[i + 1];
        } else if (std::strcmp(argv[i], "--history") == 0) {
            file.pathHistory = argv[i + 1];
        }
    }
}
