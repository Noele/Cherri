#include "Economy.h"

/**
 * Adds a user to the database
 * @param userId The ID of the user to add to the database
 */
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

/**
 * Gets a users balance
 * @param userId The ID of the user to get the balance of
 * @return An int of the users balance
 */
int Economy::getUserCredits(std::string userId) {
    std::ifstream i("economy.json");
    nlohmann::json j;
    i >> j;
    if(!j["users"].contains(userId)) {
        Economy::addUser(userId);
    }
    return j["users"][userId]["credits"];
}

/**
 * Adds credits to a user
 * @param userId The ID of the user to add credits to
 * @param amount The amount of credits to add to the user
 */
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
/**
 * Removes credits from a user
 * @param userId The ID of the user to remove credits from
 * @param amount The amount of credits to remove from the user
 * 
 * @note removeUserCredits is just an alias of addUserCredits with the amount negatively flipped
 */
void Economy::removeUserCredits(std::string userId, int amount) {
    Economy::addUserCredits(userId, -amount);
}
