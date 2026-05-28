// geode-deps add 

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>
#include "add.hpp"

namespace addDep {

    /// @brief Checks if Mod exist on the servers
    /// @param mod_id 
    /// @return -1 if not, 0 if found, 1 if connection error1
    int checkIfModExist(const std::string& mod_id) {
        std::string cmd =
            "curl --fail -s "
            "https://api.geode-sdk.org/v1/mods/" + mod_id +
            " > NUL 2> NUL";

        int result = std::system(cmd.c_str());

        // Extract actual exit code
        // result = result >> 8;

        if (result == 22) {
            std::cerr << "The mod appears to not exist!\n";
            return -1;
        }

        if (result != 0) {
            std::cerr << "Error appeared while connecting\n";
            return 1;
        }

        return 0;
    }

    auto modifyJSON(const std::string& id) -> int {
        auto modExist = checkIfModExist(id);

        if (modExist != 0) {
            std::cout << "Mod doesn't exist!" << std::endl;
            return 1;
        }

        std::ifstream inFile("mod.json");
        if (!inFile.is_open()) {
            std::cout << "Failed to open mod.json!" << std::endl;
            return 1;
        }

        std::string content((std::istreambuf_iterator<char>(inFile)),
                         std::istreambuf_iterator<char>());
        inFile.close();

        auto result = matjson::parse(content);
        if (!result) {
            std::cout << "Failed to parse mod.json!" << std::endl;
            return 1;
        }

        auto parsed = result.unwrap();

        if (!parsed.contains("dependencies") || !parsed["dependencies"].isObject()) {
            std::cout << "No dependencies object found!" << std::endl;
         return 1;
        }

        // set the value in the dependencies object
        parsed["dependencies"][id] = ">=1.0.0";

        std::ofstream outFile("mod.json");
        if (!outFile.is_open()) {
         std::cout << "Failed to write mod.json!" << std::endl;
         return 1;
        }

        outFile << parsed.dump(4);
        return 0;
    }
} // namespace addDep



/* llvm bro */