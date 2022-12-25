#pragma once
#include <iostream>
#include <string>
#include "database.hpp"

class Menu
{
public:

	static void hello(Database &db);
	static bool main(Database &db);

	static void addRecord(Database &db);
	static void editRecord(Database &db);
	static void removeRecords(Database &db);
	static void sortRecords(Database &db);
	static void filterRecords(Database &db);

	static void addCategory(Database &db);
	static void removeCategory(Database &db, std::string category);

	static std::string passAdding();
	static bool switchEdit(Database& db, std::string name, std::string field, std::string newVal);
};