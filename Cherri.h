#include "sleepy_discord/sleepy_discord.h"
#include <iostream>
#include <regex>
#include <fmt/core.h>
#include "Toolbox.h"
#include "Config.h"

class Cherri : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override;   
    void avatar(SleepyDiscord::Message message);
};
