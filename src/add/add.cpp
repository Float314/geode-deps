// geode-deps add 

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>
#include "add.hpp"
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <format>

namespace addDep {

    std::string serverResponse(const char* id) {
        // i had to manually write this
        // dont get this for granted, geode devs >:(
        httplib::SSLClient cli("api.geode-sdk.org");

        std::string _req = std::format("/v1/mods/{0}", id);
        auto request = cli.Get(_req.c_str());
        
        if (request && request->status == 200) {
            return request->body;
        } 
        else if (request->status == 404) {
            std::cerr << "The given API Doesn't exist on the server! (HTTP Exit code 404: Not found!)" << std::endl;
            return "{}";
        }
        else {
            std::cerr << "Failed to get response from the server! Error code : " << request->status << std::endl;
            return "{}";
        }
    }

    auto modifyJSON(const std::string& id) -> int {
        auto srvrJson = serverResponse(id.c_str());

        if (srvrJson == "{}") return 1;

        auto httpRes = matjson::parse(srvrJson);
        if (!httpRes) {
            std::cerr << "Failed to parse Server Response (application/json)" << std::endl;
        }
        auto root = httpRes.unwrap();

        matjson::Value latest = root["payload"]["versions"][0]["version"];

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