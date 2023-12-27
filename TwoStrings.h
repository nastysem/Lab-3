#include "SubstringSearch.h"
#pragma once
class TwoStrings : public SubstringSearch {
private:
	std::string firstLine;
public:
	void client() override;
	void checkTwoStrings();
	std::string makeString(std::vector<char> letters);
};