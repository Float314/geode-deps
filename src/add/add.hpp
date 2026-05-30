#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <matjson.hpp>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>

namespace addDep {
    std::string serverResponse(const char* id);
    auto modifyJSON(const std::string& id) -> int;
}