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

	static std::vector<std::string> getAll(std::string path);
	static bool validate(std::string checkLine, std::string pass);
	static std::string decipher(std::string line);
	static std::string decipher(std::string line, std::string pass);
	static std::vector<std::string> decodeAll(std::string path, int & records, int & categories, std::string pass);
	static void read(Database &db, std::string path, std::string pass);
};

