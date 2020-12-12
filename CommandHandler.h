#include "Response.h"
#include "sleepy_discord/sleepy_discord.h"
#include <fmt/core.h>
#include "Toolbox.h"

class CommandHandler {
public:
    static Response avatar(SleepyDiscord::Message message, SleepyDiscord::User user);
};
