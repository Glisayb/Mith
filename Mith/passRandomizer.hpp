#pragma once
#include <string>

class PassRandomizer
{
public:
	static char randSpecial();
	static char randGreat();
	static char randLetter();

	/// <summary>pobiera od uzytkownika informacje i na ich podstawie genereuje pseudo losowe haslo
	/// 
	/// </summary>
	/// <returns></returns>
	std::string static randPass();

	/// <summary>ocenia w skali szkolnej zlozonosc hasla
	/// 
	/// </summary>
	/// <param name="credits"></param>
	/// <param name="limit"></param>
	/// <returns></returns>
	int static ratePassSafty(const std::string &pass);

	/// <summary>pobiera i strzeze (by wartosci byly liczbowe), a takze beszta i upomina
	/// 
	/// </summary>
	/// <param name="credits"></param>
	/// <param name="limit"></param>
	/// <returns></returns>
	int static getLimitedValue(const std::string &credits, const size_t &limit);

};

