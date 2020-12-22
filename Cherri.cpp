#include "Cherri.h"
Command* Cherri::commands[] = {new Avatar("avatar"), new Daily("daily"), new Balance("balance")}; // Hold instances of our commands in an array
void Cherri::onMessage(SleepyDiscord::Message message) {
    // Split the message at spaces
    std::istringstream iss(message.content);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    // Instantiate for scope
    Response response;
    SleepyDiscord::User contextUser;
    
    // If a user has been mentioned, set them as the context user, else set it as the message author
    try { 
        contextUser = results.size() == 1 ? message.author : getUser(Toolbox::regexRemove(results[1], "[^0-9]+"));
    } catch (const std::exception& e) {
        contextUser = message.author;
    }
    
    // If the message starts with our prefix + one of our commands names, execute it and retrive its response
    for(Command* c : Cherri::commands) {
        if (message.startsWith(Config::prefix + c->name)) {
            response = c->execute(message, contextUser);
        }
    }
    
    // Switch on response type
    switch(response.rtype) {
        case Response::type::embed: // If the response type is embed
            sendMessage(message.channelID, response.rmessage, response.rembed); // Send a blank message* along with the response embed
            break;
        case Response::type::message: // If the response type is message
            sendMessage(message.channelID, response.rmessage); // Send the response message
            break;
        case Response::type::action: // If the response type is action
            break; // Yet to be implemented
    }
} 

// * Due to a bug, a "-" will be sent along side the embed