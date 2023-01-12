#pragma once
#include <string>

class Account
{
private:
	std::string name;
	std::string pass;
	std::string category;
	std::string website;
	std::string login;

public:
	/// <summary>obiekt "konto" przechowujacy zestaw danych o uzywanym hasle
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <param name="pass"></param>
	/// <param name="category"></param>
	/// <param name="website"></param>
	/// <param name="login"></param>
	Account(std::string name,
		std::string pass,
		std::string category,
		std::string website,
		std::string login);

	Account(std::string name,
		std::string pass,
		std::string category);

	/// <summary>funkcja przedstawia w zaaranzowany sposob komplet danych na temat konta na ekranie
	/// 
	/// </summary>
	void print() const;

	void setName(std::string const &newName);
	void setPass(std::string const &newPass);
	void setCategory(std::string const &newCategory);
	void setWebsite(std::string const &newWebsite);
	void setLogin(std::string const &newLogin);

	std::string getName() const;
	std::string getPass() const;
	std::string getCategory() const;
	std::string getWebsite() const;
	std::string getLogin() const;

};

