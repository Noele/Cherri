#include "Config.h"
std::string Config::token;
std::string Config::prefix;
void Config::collect() {
    std::ifstream i("config.json");
    nlohmann::json j;
    i >> j;   
    Config::token = j["token"];
    Config::prefix = j["prefix"];
}
