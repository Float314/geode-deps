#pragma once
#include <iostream>
#include <iostream>
#include "argparse.hpp"
#include <string_view>

#include <string_view>

enum class cliactions {
    Add,
    Delete, 
    Help,
    License,
    Inv /* Invalid safeguard */
};

cliactions parseArgs(int argc, char* argv[]);