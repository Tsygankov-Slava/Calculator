#pragma once

#include <string>

#include "../File/File.h"
#include "../isDebug/isDebug.h"

struct Arguments {
    void checkArguments(int argc, char *argv[], std::string &exp, File &file);
};
