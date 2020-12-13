#include "sleepy_discord/sleepy_discord.h"
class Response {
public:
    enum type {embed, message, action};
    std::string rmessage;
    SleepyDiscord::Embed rembed;
    Response::type rtype;
    Response (std::string rmessage, SleepyDiscord::Embed rembed, Response::type responseType) {
        this->rmessage = rmessage;
        this->rembed = rembed;
        this->rtype = responseType;
    }
    Response() {}
};
