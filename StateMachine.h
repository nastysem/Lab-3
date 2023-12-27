#include <vector>
#include <map>
#include <string>
using namespace std;
#pragma once //сделать потом без этого
//при создании норм репозитория сделаю класс FiniteAutomata, назову state condition
template <typename State, typename Alphabet>
class StateMachine {
protected:
	std::vector<State> states;
	std::vector<Alphabet> abc;
	State finalState;
	State firstState;
	std::map<pair<State, Alphabet>, State> transitions;
public:
	void setStates(const std::vector<State>& var1) {
		this->states = var1;
	}
	void setFirst(const State& var1) {
		this->firstState = var1;
	}
	void setFinal(const State& var1) {
		this->finalState = var1;
	}
	void setAlphabet(const std::vector <Alphabet>& var1) {
		this->abc = var1;
	}
	void setTransitions(const std::map<pair<State, Alphabet>, State>& var1) {
		this->transitions = var1;
	}
	bool checkString(const std::vector<Alphabet>& var1) {
		State thisState = this->firstState;
		for (auto& letter : var1) {
			auto iterator = transitions.find({ thisState, letter });
			if (iterator != transitions.end()) {
				thisState = iterator->second;
			}
			else return false;
		}
		return thisState == this->finalState;
	}
	bool checkSubstring(const string& line, const string& substring) {
		for (int i = 0; i < line.length() - substring.length() + 1; i++) {
			if (checkString(std::vector<Alphabet>(line.begin() + i, line.begin() + i + substring.length())) + 1) {
				return true;
			}
		}
		return false;
	}
};