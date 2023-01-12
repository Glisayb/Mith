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
}

Account::Account(
	std::string name,
	std::string pass,
	std::string category) : Account(
		name,
		pass,
		category, "\0", "\0") {}

std::string Account::getName() const { return this->name; };
std::string Account::getPass() const { return this->pass; };
std::string Account::getCategory() const { return this->category; };
std::string Account::getWebsite() const { return this->website; };
std::string Account::getLogin() const { return this->login; };

void Account::setName(const std::string &name) { this->name = name; std::cout << "Nazwa zmieniona na : " << name << std::endl; };
void Account::setPass(const std::string &pass) { this->pass = pass; std::cout << "Haslo - " << name << " zmienione na : " << pass << std::endl; };
void Account::setCategory(const std::string &category) { this->category = category; std::cout << "Kategoria - " << name << " zmieniona na : " << category << std::endl; };
void Account::setWebsite(const std::string &website) { this->website = website; std::cout << "Strona - " << name << " zmieniona na : " << website << std::endl; };
void Account::setLogin(const std::string &login) { this->login = login; std::cout << "Login - " << name << " zmieniony na : " << login << std::endl; };

void Account::print() const {
	std::cout << "Nazwa : " << name << std::endl;
	std::cout << "Haslo : " << pass << std::endl;
	std::cout << "Kategoria : " << category << std::endl;
	if (!website.empty()) {
		std::cout << "Strona : " << website << std::endl;
	}
	if (!login.empty()) {
		std::cout << "Login : " << login << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}