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

	/// <summary>tworzy wektor zakodowanych linii z pliku plaskiego
	/// 
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	static std::vector<std::string> getAll(const std::string &path);
	/// <summary>sprawdza poprawnosc hasla
	/// 
	/// </summary>
	/// <param name="path"></param>
	/// <param name="pass"></param>
	/// <returns></returns>
	static bool validate(const std::string &path, const std::string &pass);
	/// <summary>szyfruje informacje niezabezpieczane haslem
	/// 
	/// </summary>
	/// <param name="line"></param>
	/// <returns></returns>
	static std::string decipher(const std::string &line);
	/// <summary>szyfruje informacje zabezpieczane haslem
	/// 
	/// </summary>
	/// <param name="line"></param>
	/// <param name="pass"></param>
	/// <returns></returns>
	static std::string decipher(const std::string &line, const std::string &pass);
	/// <summary>przeksztalca wektor zakodowanych linii w wektor niezakodowanych
	/// 
	/// </summary>
	/// <param name="path"></param>
	/// <param name="records"></param>
	/// <param name="categories"></param>
	/// <param name="pass"></param>
	/// <returns></returns>
	static std::vector<std::string> decodeAll(const std::string &path, int & records, int & categories, const std::string &pass);
	/// <summary>wczytuje odkowane linie do bazy danych jako obiekty Account
	/// 
	/// </summary>
	/// <param name="db"></param>
	/// <param name="path"></param>
	/// <param name="pass"></param>
	static void read(Database &db, const std::string &path, const std::string &pass);
};

