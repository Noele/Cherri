#include "Economy.h"

void Economy::addUser(std::string userId) {
    nlohmann::json j;
    j[userId]["credits"] = 0;
    
    std::ifstream i("economy.json");
    nlohmann::json jsonFile;
    i >> jsonFile;
    
    jsonFile["users"].merge_patch(j);
    std::ofstream o("economy.json");
    o << std::setw(4) << jsonFile << std::endl;
}

int Economy::getUserCredits(std::string userId) {
    std::ifstream i("economy.json");
    nlohmann::json j;
    i >> j;
    if(!j["users"].contains(userId)) {
        Economy::addUser(userId);
    }
    return j["users"][userId]["credits"];
}

void Economy::addUserCredits(std::string userId, int amount) {
    std::ifstream i("economy.json");
    nlohmann::json j;
    i >> j;
    if(!j["users"].contains(userId)) {
        Economy::addUser(userId);
    }
    j["users"][userId]["credits"] = Economy::getUserCredits(userId) + amount;
    
    std::ofstream o("economy.json");
    o << std::setw(4) << j << std::endl;
}

void Economy::removeUserCredits(std::string userId, int amount) {
    Economy::addUserCredits(userId, -amount);
}
