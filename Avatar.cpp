#include "Avatar.h"

Response Avatar::execute(SleepyDiscord::Message message, SleepyDiscord::User user) {
    SleepyDiscord::Embed embed;
    embed.title = user.username + "'s Avatar";
    embed.color = 0xFF0000;
    embed.image.url = fmt::format("https://cdn.discordapp.com/avatars/{}/{}{}?size=1024",  
                                    std::string(user.ID), user.avatar, Toolbox::returnExtention(user.avatar));
    
    Response r("e", embed, Response::type::embed);
    
    return r;
}
