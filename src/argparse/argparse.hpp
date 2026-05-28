#include <iostream>

enum class actions {
    Add,
    Delete, 
    Help,
    License,
    Inv /* Invalid safeguard */
};

actions parseArgs(int argc, char* argv[]);