#pragma once
#include "account.hpp"
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Database
{
private:
	/// <summary>wektor przechowujacy liste kategorii
	/// 
	/// </summary>
	std::vector<std::string> listOfCategories;
	/// <summary>wektor przechowujacy liste kont
	/// wektor przechowujacy liste obiektow klasy Account
	/// </summary>
	std::vector<Account> listOfAccounts;

public:
	/// <summary>Konstruktor, jaki jest kazdy widzi
	/// "Nowsze Ateny"
	/// </summary>
	Database();

	std::vector<std::string> getCat() const;
	std::vector<Account> getDb() const; 
	std::vector<Account>* getDbPtr();

	/// <summary>sprawdza czy podana kategoria widnieje juz w bazie
	/// 
	/// </summary>
	bool isOnCatList(const std::string &category) const;
	/// <summary>podaje pozycje na liscie kategorii
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	size_t positionOnCatList(const std::string &name) const;
	/// <summary>dodaje kategorie jesli jej jeszcze nie ma
	/// 
	/// </summary>
	/// <param name="category"></param>
	/// <returns></returns>
	bool addCategory(const std::string &category);
	/// <summary>usuwa kategorie i wszystkie jej skladowe
	/// 
	/// </summary>
	/// <param name="category"></param>
	/// <returns></returns>
	bool removeCategory(const std::string &category);
	/// <summary>pokazuje liste kategorii na ekranie
	///
	/// </summary>
	void printCategorys() const;

	/// <summary>sprawdza czy konto o danej nazwie jest wpisane do bazy
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool isPresent(const std::string &name) const;
	/// <summary>podaje pozycje konta o podanej nazwie w bazie
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	size_t position(const std::string &name) const;
	/// <summary>zwraca wskaznik dla podanego konta
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	Account* find(const std::string & name);


	/// <summary>pokazuje liste kont na ekranie
	/// 
	/// </summary>
	/// <param name="listAcc"></param>
	static void print(const std::vector<Account>& listAcc);
	/// <summary>dodaje konto do bazy
	/// 
	/// </summary>
	/// <param name="account"></param>
	void add(const Account& account);

	/// <summary>usuwa z bazy podane konta z listy
	/// 
	/// </summary>
	/// <param name="listAcc"></param>
	void remove(const std::vector<Account> &listAcc);
	/// <summary>sortuje baze wedlug 2 podanych atrybutow
	/// 
	/// </summary>
	/// <param name="firstFilter">atrubut uno</param>
	/// <param name="secondFilter">atrubut drugie uno</param>
	void sortIt(const size_t &firstFilter, const size_t &secondFilter);

	/// <summary>zwraca z zadanej listy kont, liste kont o zadanych kryteriach 
	/// 
	/// </summary>
	/// <param name="listAcc"></param>
	/// <param name="filter"></param>
	/// <param name="val"></param>
	/// <returns></returns>
	static std::vector<Account> filter(const std::vector<Account> &listAcc, const size_t &filter, const std::string &val);

	/// <summary>okresla stopien przywiazania do konkretnych ciagow znakowych
	/// 
	/// </summary>
	/// <param name="pass"></param>
	/// <returns></returns>
	size_t passUses(const std::string& pass) const;


};


