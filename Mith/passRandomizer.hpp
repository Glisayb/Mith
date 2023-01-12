#pragma once
#include <string>

class PassRandomizer
{
public:
	static char randSpecial();
	static char randGreat();
	static char randLetter();

	std::string static randPass();

	int static ratePassSafty(const std::string &pass);

	int static getLimitedValue(const std::string &credits, const size_t &limit);

};

