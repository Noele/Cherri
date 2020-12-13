#include "Command.h"
#include <fmt/core.h>

class Avatar : public Command {
public:
    using Command::Command;
    Response execute(SleepyDiscord::Message message, SleepyDiscord::User user) override;
};
