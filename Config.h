#include "json.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

class Config {
public:
    static void collect();
    static std::string token;
    static std::string prefix;
};
