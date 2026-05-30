/* Argparse - Argument parser. Made by me (Float314) 
    Internal module, not an external library. So the 
    License would apply the same as the program. 

    Again, THIS IS NOT AN EXTERNAL LIBRARY. CODE WAS NOT
    COPIED FROM AN EXTERNAL CODE. IF CODE WAS FOUND TO 
    BE MATCHED, IT IS A SHEER CO-INCIDENCE AND SHOULD BE 
    NOTIFIED.
*/

#include <iostream>
#include "argparse.hpp"
#include <string_view>

#include <string_view>

cliactions parseArgs(int argc, char* argv[]) {
    if (argc < 2) return cliactions::Inv;

    std::string_view fa = argv[1];

    if (fa == "add") return cliactions::Add;
    else if (fa == "delete") return cliactions::Delete;
    else if (fa == "-h" || fa == "--help" || fa == "help") {
        if (argc >= 3) {
            std::string_view sa = argv[2];
            if (sa == "--license") return cliactions::License;
        }
        return cliactions::Help;
    } else return cliactions::Inv;
}