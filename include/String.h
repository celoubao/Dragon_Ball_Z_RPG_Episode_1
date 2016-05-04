#ifndef DRAGON_BALL_Z_RPG_EDITION_STRING_H
#define DRAGON_BALL_Z_RPG_EDITION_STRING_H

#include <string>
#include <cctype>

using namespace std;

namespace utils {
    /**
     * Converts a string to lowercase
     **/
    string toLowercase(string s) {
        string finalString = "";
        for (size_t i = 0; i < s.length(); i++) {
            finalString += std::tolower(s.at(i));
        }
        return finalString;
    }

    /**
     * Converts a string to uppercase
     */
    string toUppercase(string s) {
        string finalString = "";
        for (size_t i = 0; i < s.length(); i++) {
            finalString += std::toupper(s.at(i));
        }
        return finalString;
    }
}

#endif //DRAGON_BALL_Z_RPG_EDITION_STRING_H
