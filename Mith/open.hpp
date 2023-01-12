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

	static std::vector<std::string> getAll(const std::string &path);
	static bool validate(const std::string &path, const std::string &pass);
	static std::string decipher(const std::string &line);
	static std::string decipher(const std::string &line, const std::string &pass);
	static std::vector<std::string> decodeAll(const std::string &path, int & records, int & categories, const std::string &pass);
	static void read(Database &db, const std::string &path, const std::string &pass);
};

