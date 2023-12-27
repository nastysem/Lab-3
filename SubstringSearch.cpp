#include "SubstringSearch.h"
std::vector<char> SubstringSearch::makeABC(std::string& line) {
    std::vector<char> abc;
    for (int i = 0; i < line.length(); i++) {
        if (std::find(abc.begin(), abc.end(), line[i]) == abc.end())
            abc.push_back(line[i]);
    }
    return abc;
}
std::vector<int> SubstringSearch::prefix_function(string& line) {
    int n = line.length();
    vector<int> pi(n + 1);
    for (int i = 1; i < n + 1; i++) {
        int j = pi[i - 1];
        while (j > 0 && line[i] != line[j])
            j = pi[j - 1];
        if (line[i] == line[j]) j++;
        pi[i] = j;
        return pi;
    }
}
void SubstringSearch::client() {
    std::cout << "Enter your string: ";
    std::cin >> line;
    std::cout << "Enter your substring: ";
    std::cin >> substring;
    this->setAlphabet(this->makeABC(this->line));
    this->setFirst(0);
}
void SubstringSearch::setTransitionTable() {
    this->setFinal(this->substring.length());
    std::vector<int> st;
    for (int i = 0; i < substring.length() + 1; i++) {
        st.push_back(i);
    }
    this->setStates(st);
    std::map<pair<int, char>, int> tr;
    std::vector<int> pi = prefix_function(substring);
    for (char letter : this->abc) {
        if (letter == substring[0]) {
            tr[{0, letter}] = 1;  
        }
        else {
            tr[{0, letter}] = 0;
        }
    }
    for (int state = 1; state < substring.length(); state++) {
        for (char letter : this->abc) {
            if (letter == substring[state]) {
                tr[{state, letter}] = state + 1;
            }
            else {
                tr[{state, letter}] = tr[{pi[state], letter}];
            }
        }
    }
    for (char letter : this->abc) {
        tr[{substring.length(), letter}] = tr[{pi[substring.length()], letter}];
    }
    setTransitions(tr);
}
void SubstringSearch::solution() {
    if (this->checkSubstring(line, substring)) {
        std::cout << "contains" << std::endl;
    }
    else {
        std::cout << "doesn't contain" << std::endl;
    }

}
