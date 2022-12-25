#include "database.hpp"

Database::Database() {}

std::vector<Account> Database::getDb() const { return listOfAccounts; };
std::vector<std::string> Database::getCat() const { return listOfCategories; };

bool Database::isOnCatList(std::string newCategory) const {
	bool isOnCatList = false;
	for (std::string category : listOfCategories) {
		if (newCategory == category) { isOnCatList = true; }
	}
	return isOnCatList;
}

void Database::printCategorys() const {
	for (auto category : listOfCategories) {
		std::cout << category << std::endl;
	}
	std::cout << std::endl;
}

void Database::addCategory(std::string newCategory) {
	bool isPresent = isOnCatList(newCategory);
	if (isPresent) { std::cout << "Taka kategoria juz jest" << std::endl; }
	else listOfCategories.push_back(newCategory);
}

void Database::removeCategory(std::string category) {}

bool Database::isPresent(std::string name) const {
	bool isPresent = false;
	auto db = this->getDb();
	for (auto account : db)
	{
		if (account.getName() == name) { isPresent = true; break; }
	}
	return isPresent;
}
size_t Database::position(std::string name) const {
	size_t position = -1;
	auto db = this->getDb();
	for (size_t i = 0; i < db.size(); i++)
	{
		if (db[i].getName() == name) { position = i; }
	}
	return position;
}

Account* Database::find(std::string name) const {
	Account* accountPtr = nullptr;
	auto db = this->getDb();
	for (auto account : db)
	{
		if (account.getName() == name) { accountPtr = &account; break; }
	}
	return accountPtr;
}



void Database::print(std::vector<Account> listAcc){
	for (Account acc : listAcc)	{acc.print();}
}

void Database::add(const Account& account) {
	if (!isPresent(account.getName())) {
		listOfAccounts.push_back(account);
		std::cout << "Konto : " << account.getName() << " - dopisane" << std::endl;
	}
	else { std::cout << "Konto : " << account.getName() << " ju¿ istnieje" << std::endl;
	}
}

auto eqName = [](Account acc, std::string val)->bool { return(acc.getName() == val); };
auto eqPass = [](Account acc, std::string val)->bool { return(acc.getPass() == val); };
auto eqCat = [](Account acc, std::string val)->bool { return(acc.getCategory() == val); };
auto eqWeb = [](Account acc, std::string val)->bool { return(acc.getWebsite() == val); };
auto eqLogin = [](Account acc, std::string val)->bool { return(acc.getLogin() == val); };
auto contName = [](Account acc, std::string val)->bool { return(acc.getName().find(val)!=-1); };
auto contPass = [](Account acc, std::string val)->bool { return(acc.getPass().find(val) != -1); };
auto contCat = [](Account acc, std::string val)->bool { return(acc.getCategory().find(val) != -1); };
auto contWeb = [](Account acc, std::string val)->bool { return(acc.getWebsite().find(val) != -1); };
auto contLogin = [](Account acc, std::string val)->bool { return(acc.getLogin().find(val) != -1); };

std::vector<Account> Database::filter(std::vector<Account> & listAcc, size_t filter, std::string val) {
	std::vector<Account> filtredList;
	bool match;
	for (Account account : listAcc)
	{
		switch (filter)
		{
		case 1: match = eqName(account, val); break;
		case 2: match = eqPass(account, val); break;
		case 3: match = eqCat(account, val); break;
		case 4: match = eqWeb(account, val); break;
		case 5: match = eqLogin(account, val); break;
		case 6: match = contName(account, val); break;
		case 7: match = contPass(account, val); break;
		case 8: match = contCat(account, val); break;
		case 9: match = contWeb(account, val); break;
		case 10: match = contLogin(account, val); break;
		default:  match = false; break;
		}
		if (match) { filtredList.push_back(account); }
	}
	return filtredList;
}

void Database::remove(std::vector<Account> &accList) {
	for (Account acc : accList)
	{
		auto it = std::find(listOfAccounts.begin(), listOfAccounts.end(), acc);
		if (it != listOfAccounts.end()) {
			std::cout << "Usuwam konto : " << acc.getName() << std::endl;
			listOfAccounts.erase(it);
		}
	}
}
//void Database::sort(std::function<Database>) {}




