#include "Config.h"
std::string Config::token;
std::string Config::prefix;

bool fexists(const char *filename)
{
  std::ifstream ifile(filename);
  return (bool)ifile;
}

void Config::collect() {
    if(!fexists("config.json")) {
        nlohmann::json j;
        j["token"] = "";
        j["prefix"] = "";
        
        std::ofstream o("config.json");
        o << std::setw(4) << j << std::endl;
        
        std::cout << "Config.json created, Please populate its \"token\" and \"prefix\" fields." << std::endl;
        exit(0);
    }
    std::ifstream i("config.json");
    nlohmann::json j;
    i >> j;   
    Config::token = j["token"];
    Config::prefix = j["prefix"];
}
