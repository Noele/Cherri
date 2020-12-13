#include "Cherri.h"
Command* Cherri::commands[] = {new Avatar("avatar"), new Daily("daily"), new Balance("balance")};
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
    
    for(Command* c : Cherri::commands) {
        if (message.startsWith(Config::prefix + c->name)) {
            response = c->execute(message, contextUser);
        }
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
