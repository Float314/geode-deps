#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>

namespace addDep {
    std::string serverResponse(const char* id);
    auto modifyJSON(const std::string& id) -> int;
}