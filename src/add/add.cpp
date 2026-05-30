// geode-deps add 

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>
#include "add.hpp"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

namespace addDep {

    std::string serverResponse(const char* id) {
        /* Someone please just help me out here 
           curl request - curl -X 'GET' 'https://api.geode-sdk.org/v1/mods/{id}' -H 'accept: application/json'

           Then to get the JSON and the below would modify th4e JSON
           The catch is, however, dat, shouldn't use std::system for CLI Piping (Vulnerablity issue)
        */
    }

    auto modifyJSON(const std::string& id) -> int {
        auto srvrJson = serverResponse(id.c_str());

        auto httpRes = matjson::parse(srvrJson);
        if (!httpRes) {
            std::cerr << "Failed to parse Server Response (application/json)" << std::endl;
        }
        auto root = httpRes.unwrap();

        matjson::Value latest = root["payload"]["versions"][0];

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
        parsed["dependencies"][id] = latest;

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