#pragma once
#include <string>

class PassRandomizer
{
public:
	static char randSpecial();
	static char randGreat();
	static char randLetter();

	std::string static randPass();

	int static ratePassSafty(std::string const pass);

	int static getLimitedInt(std::string const credits, size_t limit);

};

