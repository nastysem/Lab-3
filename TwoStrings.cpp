#include "TwoStrings.h"
void TwoStrings::client() {
    std::cout << "Enter your first string: ";
    std::cin >> firstLine;
    std::cout << "Enter your second string. It must be longer then first one: ";
    std::cin >> line;
    this->setAlphabet(this->makeABC(this->line));
    this->setFirst(0);
}
std::string TwoStrings::makeString(std::vector<char> letters) {
    std::string str = "";
    for (int i = 0; i < letters.size(); i++) {
        str = str + letters[i];
    }
    return str;
}
void TwoStrings::checkTwoStrings() {
    client();
    std::vector<std::string> str;
    substring = "";
    int length = firstLine.length();
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < firstLine.length(); i++) {
            substring = makeString(std::vector<char>(firstLine.begin(), firstLine.begin() + i + 1));
            setTransitionTable();
            if (checkSubstring(line, substring))
                str.push_back(substring);
        }
        firstLine = makeString(std::vector<char>(firstLine.begin() + 1, firstLine.end()));
    }
    std::string max = "";
    for (int i = 0; i < str.size(); i++) {
        if (max.length() < str[i].length())
            max = str[i];
    }
    if (str.empty()) {
        std::cout << "These strings don't have common substrings" << std::endl;
    }
    else {
        std::cout << "Max string is " << max << std::endl;
    }
}