#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include "database.hpp"
#include "open.hpp"

namespace formatVariables {
	static size_t alfa = 32;
	static size_t omega = 126;
	static size_t beta = 64;
	static size_t margin = 20;
	static size_t limit = 30;
}

class Save
{
private:

public:

	static void saveAll(Database db, std::string path, std::string pass);
	static std::string buzzing(std::string getted);
	static std::string buzzing(std::string getted, std::string pass);
	static void nastyAccesSave(std::string wrongPass, std::string path, std::string timeStmp);
};

