#include "Toolbox.h"

std::string Toolbox::returnExtention(std::string userAvatar) {
    return std::string(userAvatar.rfind("a_", 0) == 0 ? ".gif" : ".png");
}

std::string Toolbox::regexRemove(std::string string, std::string regex) {
    std::regex e (regex);
    return std::regex_replace(string, e, "");
}
