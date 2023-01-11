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

	void setName(std::string newName);
	void setPass(std::string newPass);
	void setCategory(std::string newCategory);
	void setWebsite(std::string newWebsite);
	void setLogin(std::string newLogin);

	std::string getName() const;
	std::string getPass() const;
	std::string getCategory() const;
	std::string getWebsite() const;
	std::string getLogin() const;

};

