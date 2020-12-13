#include "Command.h"
#include "Economy.h"
#pragma once 
class Daily : public Command {
public:
    using Command::Command;
    Response execute(SleepyDiscord::Message message, SleepyDiscord::User user) override;
};
