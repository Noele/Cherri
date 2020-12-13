#include "Command.h"
#include <fmt/core.h>
#include "Economy.h"
#pragma once 
class Balance : public Command {
public:
    using Command::Command;
    Response execute(SleepyDiscord::Message message, SleepyDiscord::User user) override;
};
