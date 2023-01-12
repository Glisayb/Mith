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
	Account(std::string name,
		std::string pass,
		std::string category,
		std::string website,
		std::string login);

	Account(std::string name,
		std::string pass,
		std::string category);

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

