#pragma once
#include <iostream>
#include <string>
#include "database.hpp"
#include "save.hpp"
#include "passRandomizer.hpp"
#include "open.hpp"

class Menu
{
private:
	Database db;
	std::string path;
	std::string pass;

public:
	/// obiekt pozwala rozpoczac nawigacje po aplikacji Mithrandir
	/// 
	/// </summary>
	/// <param name="path"></param>
	Menu(std::string path);
	/// menu powitalne, sprawdza haslo
	/// 
	/// menu kaze sprawdza haslo i wczytuje zapisana baze, lub tworzy nowa i prosi o dodanie hasla
	/// <returns></returns>
	bool hello();
	/// podstawowe menu nawigacyjne
	/// 
	/// menu pozwala nawigowac i wielokrotnie wykonywaz polecenia az do wywolania zadania zamkniecia
	/// <returns></returns>
	bool main();

	/// polecenie dodania rekordu
	/// 
	/// </summary>
	void addRecord();
	/// polecenie edycji rekordu<summary>
	/// dupa
	/// </summary>
	void editRecord();
	void removeRecords();
	void sortRecords();
	void filterRecords() const;

	void addCategory();
	void removeCategory();

	void printCategorys() const;

	void changePass();
	void changePath();

	void save() const;

	std::vector<Account> listRecords() const;
	bool switchEdit(const std::string& name, const std::string& field, const std::string& newVal);

	static std::string addPass();

	static std::string getLimitedString(const std::string &credits);
	static size_t getLimitedValue(const std::string &credits, const size_t &max);
	static bool isFilePresent(const std::string &name);
	static std::string txtSufix(const std::string &path);
};