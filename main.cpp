#include "sleepy_discord/sleepy_discord.h"
#include <fmt/core.h>
#include "Cherri.h"

int main() {
    Config::collect();
    
	Cherri client(Config::token, SleepyDiscord::USER_CONTROLED_THREADS);
	client.run();
}
