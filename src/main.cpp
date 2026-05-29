#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

#include "add/add.hpp"
#include "argparse/argparse.hpp"
#include "delete/delete.hpp"
#include "helpStrings.hpp"


 
int actX(int argc, char* argv[]) { 
    auto act = parseArgs(argc, argv);

    switch (act) {
        case actions::Add: 
            addDep::modifyJSON(argv[2]);
            break;
        case actions::Delete:
            deleteRec::deleteKey(argv[2]);
            break;
        case actions::Help:
            helpStr();
            break;
        case actions::License:
            licenseStr();
            break;
        case actions::Inv: 
            std::cerr << "something went wrong! Exiting program." << std::endl;
            return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    auto actionlol = actX(argc, argv);
    return actionlol;
}