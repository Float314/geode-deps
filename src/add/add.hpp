#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>

namespace addDep {
    int checkIfModExist(const std::string& mod_id);
    auto modifyJSON(const std::string& id) -> int;
}