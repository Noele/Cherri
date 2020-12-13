#include "Toolbox.h"

/**
 * Gets the correct extension of a users avatar
 * @param userAvatar The hash of a given users avatar
 * 
 * @note returns .gif if userAvatar starts with a_, else .png
 */
std::string Toolbox::returnExtention(std::string userAvatar) {
    return std::string(userAvatar.rfind("a_", 0) == 0 ? ".gif" : ".png");
}

/**
 * Removes text from a message using the given regex
 * @param string The string we should remove text from
 * @param regex The regex to validate the removal from string
 */
std::string Toolbox::regexRemove(std::string string, std::string regex) {
    std::regex e (regex);
    return std::regex_replace(string, e, "");
}
