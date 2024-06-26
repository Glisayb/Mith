#include "passRandomizer.hpp"
#include "save.hpp"
#include <iostream>

using namespace formatVariables;

char PassRandomizer::randSpecial() { return ((rand() % 32) + 32); }
char PassRandomizer::randGreat() { return ((rand() % 25) + 65); }
char PassRandomizer::randLetter() { return ((rand() % 25) + 97); }

std::string PassRandomizer::randPass() {
		
	int length, capitals, specials, caps_spes;
	std::string	pass, letPrint;

	length = getLimitedValue("Podaj dlugosc", limit);
	capitals = getLimitedValue("Podaj ilosc wielkich liter", length);
	specials = getLimitedValue("Podaj ilosc znakow specjalnych : ", length - capitals);

	caps_spes = capitals + specials;

	for (size_t i = 0; i < length; i++)
		{
		char a;
		if (capitals > 0) { a = randGreat(); capitals--; }
		else if (specials > 0) { a = randSpecial(); specials--; }
		else { a = randLetter(); }
		pass.push_back(a);

	}
	for (size_t i = 0; i < caps_spes; i++)
	{
		int j = rand() % length;
		char b = pass[j];
		pass[j] = pass[i];
		pass[i] = b;
	}
	std::cout << "Jesli chcesz zobaczyc haslo na ekranie wpisz 0 : " << std::endl;
	std::cin >> letPrint;
	if (letPrint == "0") { std::cout << pass << std::endl; }
	return pass;
}

int PassRandomizer::ratePassSafty(const std::string &pass) {
	int rating = 0;
	int great = 0;
	int specials = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if ('A' <= pass[i] && pass[i] <= 'Z') { great++; }
		else if ('a' > pass[i] && pass[i] > 'z') { specials++; }
	}
	rating = (specials < 2 ? specials : 2) + (great < 2 ? great : 2) + (pass.size() < 9 ? (int)(pass.size() / 3) : 2);
	std::cout << "Ocena bezpieczenstwa tego hasla to : " << rating << " na 6 pkt" << std::endl;
	return rating;
}

int PassRandomizer::getLimitedValue(const std::string &credits, const size_t &limit) {
	size_t size = limit;
	std::string stringIn;
	while (size >= limit) {
		std::cout << credits << ", nie wiecej niz : " << limit << std::endl;
		std::cin >> stringIn;
		try
		{
			size = stoi(stringIn);
		}
		catch (const std::exception&)
		{
			size = limit;
			std::cout << "!!!Nie podano liczby!!!" << std::endl;
		}
	}
	return size;
}