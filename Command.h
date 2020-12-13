#include "sleepy_discord/sleepy_discord.h"
#include "Response.h"
#include "Toolbox.h"
#pragma once 
class Command {
public:
    virtual Response execute(SleepyDiscord::Message message, SleepyDiscord::User user) {Response r;return r;};
    std::string name;
    Command() = default;
    Command(std::string name) {this->name = name;}
    ~Command() {};
};
