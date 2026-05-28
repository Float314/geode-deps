#include <iostream>
#include <fstream> 
#include <matjson.hpp>

namespace deleteRec {

auto deleteKey(const std::string& id) -> int {
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

    if (!parsed["dependencies"].contains(id)) {
        std::cout << "Mod ID \'" << id << "\' not found in dependencies!" << std::endl;
        return 1;
    }

    parsed["dependencies"].erase(id);

    std::ofstream outFile("mod.json");
    if (!outFile.is_open()) {
        std::cout << "Failed to write mod.json!" << std::endl;
        return 1;
    }

    outFile << parsed.dump(4);
    return 0;
}

} // deleteRec.