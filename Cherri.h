#include "sleepy_discord/sleepy_discord.h"
#include <iostream>
#include <regex>
#include "Config.h"
#include "Economy.h"
#include "Avatar.h"

class Cherri : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override;   
    
    //void daily(SleepyDiscord::Message message);
    //void balance(SleepyDiscord::Message message);
};
