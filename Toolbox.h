#include <iostream>
#include <regex>

class Toolbox {
public:
    static std::string returnExtention(std::string userAvatar);
    static std::string regexRemove(std::string string, std::string regex);
};
