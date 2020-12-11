#include "json.hpp"
#include <fstream>
#include <iomanip>
#include "sleepy_discord/sleepy_discord.h"

class Economy {
public:
    static void addUser(std::string userId);
    static int getUserCredits(std::string userId);
    static void addUserCredits(std::string userId, int amount);
    static void removeUserCredits(std::string userId, int amount);
};
