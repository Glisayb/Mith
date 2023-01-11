#pragma once
#include <iostream>
#include <string>
#include "database.hpp"
#include "save.hpp"
#include "passRandomizer.hpp"
#include "open.hpp"

class Menu
{
public:

	static bool hello(Database &db);
	static bool main(Database &db, std::string& pass, std::string& path);

	static void addRecord(Database &db);
	static void editRecord(Database &db);
	static void removeRecords(Database &db);
	static void sortRecords(Database &db);
	static void filterRecords(Database &db);

	static void addCategory(Database &db);
	static void removeCategory(Database &db);

	static void printCategorys(Database& db);

	static void changePass(std::string &pass);
	static void changePath(std::string& path);

	static void save(Database& db, std::string const pass, std::string const path);

	static std::vector<Account> listRecords(Database& db);
	static std::string addPass();
	static bool switchEdit(Database& db, std::string const name, std::string const field, std::string const newVal);

	static std::string getLimitedString(std::string const credits);
	static bool isFilePresent(const std::string& name);
	static std::string txtSufix(const std::string path);
};