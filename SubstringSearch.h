#include <iostream>
#include "StateMachine.h"
#include <algorithm>
#pragma once
class SubstringSearch: public StateMachine<int, char> {
protected:
	std::string line;
	std::string substring;

public:
	std::vector<int> prefix_function(string& line);
	std::vector<char> makeABC(string& line);
	virtual void client();
	void setTransitionTable();
	void solution();
};
