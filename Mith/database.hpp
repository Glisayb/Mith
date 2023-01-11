#pragma once
#include "account.hpp"
#include <functional>
#include <algorithm>
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

	bool isOnCatList(std::string const category) const;
	size_t positionOnCatList(std::string const name) const;
	void printCategorys() const;
	bool addCategory(std::string category);
	bool removeCategory(std::string category);

	bool isPresent(std::string) const;
	size_t position(std::string const name) const;
	Account* find(std::string const accPtr) const;
	struct NameComparator;
	size_t passUses(std::string const pass) const;
	void add(const Account& account);
	void remove(std::vector<Account> listAcc);
	void sortIt(size_t firstFilter, size_t secondFilter);
	bool compareNames(Account acc1, Account acc2);
	static std::vector<Account> filter(std::vector<Account> listAcc, const size_t filter, const std::string val);
	static void print(const std::vector<Account> listAcc);

};


