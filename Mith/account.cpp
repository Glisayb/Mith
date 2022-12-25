#include "account.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Account::Account(
	std::string name,
	std::string pass,
	std::string category,
	std::string website,
	std::string login)
{
	this->name = name;
	this->pass = pass;
	this->category = category;
	this->website = website;
	this->login = login;

	this->print();
}

Account::Account(
	std::string name,
	std::string pass,
	std::string category) : Account(
		name,
		pass,
		category, "/", "/") {}

std::string Account::getName() const { return this->name; };
std::string Account::getPass() const { return this->pass; };
std::string Account::getCategory() const { return this->category; };
std::string Account::getWebsite() const { return this->website; };
std::string Account::getLogin() const { return this->login; };

void Account::setName(std::string name) { this->name = name; std::cout << "Nazwa zmieniona na : " << name << std::endl; };
void Account::setPass(std::string pass) { this->pass = pass; std::cout << "Haslo - " << name << " zmienione na : " << pass << std::endl; };
void Account::setCategory(std::string category) { this->name = category; std::cout << "Kategoria - " << name << " zmieniona na : " << category << std::endl; };
void Account::setWebsite(std::string website) { this->name = website; std::cout << "Strona - " << name << " zmieniona na : " << website << std::endl; };
void Account::setLogin(std::string login) { this->name = login; std::cout << "Login - " << name << " zmieniony na : " << login << std::endl; };

int Account::howPassSafe(std::string pass) {
	int rating = 0;
	int great = 0;
	int specials = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if ('A' <= pass[i] && pass[i] <= 'Z') { great++; }
		else if ('a' > pass[i] && pass[i] > 'z') { specials++; }
	}
	rating = (specials < 2 ? specials : 2) + (great < 2 ? great : 2) + (pass.size() < 9 ? (int)(pass.size() / 3) : 2);
	std::cout << "Ocena bezpieczenstwa tego hasla to : " << rating << " na 6 pkt" << std::endl;
	return rating;
}

int Account::howPassSafe() const { return howPassSafe(this->pass); }

void Account::print() const {
	std::cout << "Nazwa : " << name << std::endl;
	std::cout << "Has³o : " << pass << std::endl;
	std::cout << "Kategoria : " << category << std::endl;
	if (!website.empty()) {
		std::cout << "Strona : " << website << std::endl;
	}
	if (!login.empty()) {
		std::cout << "Login : " << login << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}