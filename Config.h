#include "json.hpp"
#include <fstream>

class Config {
public:
    static void collect();
    static std::string token;
    static std::string prefix;
};
