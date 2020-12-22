#include "Daily.h"

Response Daily::execute(SleepyDiscord::Message message, SleepyDiscord::User user) {
    Economy::addUserCredits(std::string(message.author.ID), 5000);
    SleepyDiscord::Embed embed;
    embed.title = "Added 5000 credits to your account !";
    embed.color = 0x00FF00;
    
    
    Response r("-", embed, Response::type::embed);
    return r;
}
