#include "Balance.h"

Response Balance::execute(SleepyDiscord::Message message, SleepyDiscord::User user) {
    SleepyDiscord::Embed embed;
    embed.title = fmt::format("You have {} credits in your account", Economy::getUserCredits(std::string(message.author.ID)));
    embed.color = 0x00FF00;
    
    Response r("-", embed, Response::type::embed);
    return r;
}
