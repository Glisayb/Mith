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

	/// <summary>zapisuje baze do pliku plaskiego
	/// 
	/// </summary>
	/// <param name="db"></param>
	/// <param name="path"></param>
	/// <param name="pass"></param>
	static void saveAll(const Database &db, const std::string &path, const std::string &pass);
	/// <summary>dodaje do wpisow 'szum' oraz przeslania nim informacje o kontach
	/// 
	/// </summary>
	/// <param name="getted"></param>
	/// <returns></returns>
	static std::string buzzing(const std::string &getted);
	/// <summary>dodaje do wpisow 'szum' oraz przeslania nim oraz haslem informacje o kontach
	/// 
	/// </summary>
	/// <param name="getted"></param>
	/// <returns></returns>
	static std::string buzzing(const std::string &getted, const std::string &pass);
	/// <summary>zapisuje informacje o niepozadanej probie otwarcia pliku
	/// 
	/// </summary>
	/// <param name="wrongPass"></param>
	/// <param name="path"></param>
	/// <param name="timeStmp"></param>
	static void nastyAccesSave(const std::string &wrongPass, const std::string &path, const std::string &timeStmp);
};

