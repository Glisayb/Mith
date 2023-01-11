#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "database.hpp"
#include "save.hpp"

class Open
{
public :

	static std::vector<std::string> getAll(std::string const path);
	static bool validate(std::string const path, std::string const pass);
	static std::string decipher(std::string const line);
	static std::string decipher(std::string const line, std::string const pass);
	static std::vector<std::string> decodeAll(std::string path, int & records, int & categories, std::string const pass);
	static void read(Database &db, std::string const path, std::string const pass);
};

