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
	std::vector<Account>* getDbPtr();

	bool isOnCatList(const std::string &category) const;
	size_t positionOnCatList(const std::string &name) const;
	bool addCategory(const std::string &category);
	bool removeCategory(const std::string &category);
	void printCategorys() const;

	bool isPresent(const std::string &name) const;
	size_t position(const std::string &name) const;
	Account* find(const std::string & name);

	static void print(const std::vector<Account>& listAcc);
	void add(const Account& account);

	void remove(const std::vector<Account> &listAcc);
	void sortIt(const size_t &firstFilter, const size_t &secondFilter);

	struct NameComparator;
	bool compareNames(const Account &acc1, const Account &acc2) const;
	static std::vector<Account> filter(const std::vector<Account> &listAcc, const size_t &filter, const std::string &val);

	size_t passUses(const std::string& pass) const;


};


