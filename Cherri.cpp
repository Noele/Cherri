#include "Cherri.h"

void Cherri::onMessage(SleepyDiscord::Message message) {
    std::istringstream iss(message.content);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    Response response;
    SleepyDiscord::User contextUser;
    try { 
        contextUser = results.size() == 1 ? message.author : getUser(Toolbox::regexRemove(results[1], "[^0-9]+"));
    } catch (const std::exception& e) {
        contextUser = message.author;
    }

    if (message.startsWith(Config::prefix + "avatar")) {
        response = CommandHandler::avatar(message, contextUser);
    }

    switch(response.rtype) {
        case Response::type::embed: 
            sendMessage(message.channelID, response.rmessage, response.rembed);
            break;
        case Response::type::message: 
            sendMessage(message.channelID, response.rmessage);
            break;
        case Response::type::action:
            break;
    }

}  

/**
 * Economy commands 
 */
/*
void Cherri::daily(SleepyDiscord::Message message) {
    Economy::addUserCredits(std::string(message.author.ID), 5000);
    SleepyDiscord::Embed embed;
    embed.title = "Added 5000 credits to your account !";
    embed.color = 0x00FF00;
    sendMessage(message.channelID, "", embed);
}

void Cherri::balance(SleepyDiscord::Message message) {
    SleepyDiscord::Embed embed;
    embed.title = fmt::format("You have {} credits in your account", Economy::getUserCredits(std::string(message.author.ID)));
    embed.color = 0x00FF00;
    sendMessage(message.channelID, "", embed);
}*/
