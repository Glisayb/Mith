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
public:

	static void saveAll(const Database &db, const std::string &path, const std::string &pass);
	static std::string buzzing(const std::string &getted);
	static std::string buzzing(const std::string &getted, const std::string &pass);
	static void nastyAccesSave(const std::string &wrongPass, const std::string &path, const std::string &timeStmp);
};

