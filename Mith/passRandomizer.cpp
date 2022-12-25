#include "passRandomizer.hpp"
#include <iostream>

char PassRandomizer::randSpecial() { return ((rand() % 32) + 32); }
char PassRandomizer::randGreat() { return ((rand() % 25) + 65); }
char PassRandomizer::randLetter() { return ((rand() % 25) + 97); }

std::string PassRandomizer::randPass(size_t numSigns, size_t numGreat, size_t numSpecial) {

	std::string temp;
	size_t sumGreatSpec = numGreat + numSpecial;
	if (numGreat + numSpecial > numSigns) {
		std::cout << "Znaki specjalne, wielkie litery b¹dz ich suma przekraczaja cala wskazana dlugosc lancucha" << std::endl;
		return "/";
	}
	else {
		for (size_t i = 0; i < numSigns; i++)
		{
			char a;
			if (numGreat > 0) { a = randGreat(); numGreat--; }
			else if (numSpecial > 0) { a = randSpecial(); numSpecial--; }
			else { a = randLetter(); }
			temp.push_back(a);
		}
		for (size_t i = 0; i < sumGreatSpec; i++)
		{
			int j = rand() % numSigns;
			char b = temp[j];
			temp[j] = temp[i];
			temp[i] = b;
		}
		return temp;
	}
}