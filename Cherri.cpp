#include "Cherri.h"

void Cherri::onMessage(SleepyDiscord::Message message) {
    if (message.startsWith(Config::prefix + "hello")) {
			sendMessage(message.channelID, "Hello " + message.author.username);
        }
    if (message.startsWith(Config::prefix + "avatar")) {
        Cherri::avatar(message);
    }
}  

void Cherri::avatar(SleepyDiscord::Message message) {
        SleepyDiscord::User user;
        std::istringstream iss(message.content);
        std::vector<std::string> results(std::istream_iterator<std::string>{iss}, 
                                            std::istream_iterator<std::string>());
        
        try { 
                user = results.size() == 1 ? message.author : getUser(Toolbox::regexRemove(results[1], "[^0-9]+"));
                
        } catch (const std::exception& e) {
            sendMessage(message.channelID, "Please mention a user.");
            return;
        }
    
        SleepyDiscord::Embed embed;
        embed.title = user.username + "'s Avatar";
        embed.color = 0xFF0000;
        embed.image.url = fmt::format("https://cdn.discordapp.com/avatars/{}/{}{}?size=1024",  
                                        std::string(user.ID), user.avatar, Toolbox::returnExtention(user.avatar));
        
        sendMessage(message.channelID, "", embed);
}
