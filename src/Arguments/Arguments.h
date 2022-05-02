#pragma once

#include <string>

#include "../isDebug/isDebug.h"
#include "../File/File.h"

struct Arguments {
    void checkArguments(int argc, char* argv[], std::string &exp, File &file);
};

