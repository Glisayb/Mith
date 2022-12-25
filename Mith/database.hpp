#pragma once
#include "account.hpp"
#include <functional>
#include <vector>
#include <string>
#include <iostream>

class Database
{
private:

	std::vector<std::string> listOfCategories;
	std::vector<Account> listOfAccounts;

public:

	Database();

	std::vector<std::string> getCat() const;
	std::vector<Account> getDb() const;

	bool isOnCatList(std::string category) const;
	void printCategorys() const;
	void addCategory(std::string category);
	void removeCategory(std::string category);

	bool isPresent(std::string) const;
	size_t position(std::string name) const;
	Account* find(std::string accPtr) const;
	void add(const Account& account);
	void remove(std::vector<Account> &accList);
	void sort(std::function<Database>);
	static std::vector<Account> filter(std::vector<Account> &listAcc, size_t filter, std::string val);
	static void print(std::vector<Account> listAccPtr);

};


