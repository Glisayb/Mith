#pragma once
#include <string>

class PassRandomizer
{
public:
	static char randSpecial();
	static char randGreat();
	static char randLetter();

	std::string static randPass(size_t numSigns, size_t numGreat, size_t numSpecial);

};

