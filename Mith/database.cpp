#include "database.hpp"

Database::Database() {}

std::vector<Account> Database::getDb() const { return listOfAccounts; };
std::vector<Account>* Database::getDbPtr() { return &listOfAccounts; };
std::vector<std::string> Database::getCat() const { return listOfCategories; };

bool Database::isOnCatList(std::string newCategory) const {
	bool isOnCatList = false;
	for (std::string category : listOfCategories) {
		if (newCategory == category) { isOnCatList = true; }
	}
	return isOnCatList;
}
size_t Database::positionOnCatList(std::string name) const {
	int position = -1;
	for (size_t i = 0; i < listOfCategories.size(); i++)
	{
		auto category = listOfCategories[i];
		if (category == name) { position = i; }
	}
	return position;
}

void Database::printCategorys() const {
	std::cout << std::endl;
	for (auto category : listOfCategories) {
		std::cout << category << std::endl;
	}
	std::cout << std::endl;
}

bool Database::addCategory(std::string newCategory) {
	bool isPresent = isOnCatList(newCategory);
	if (!isPresent) { listOfCategories.push_back(newCategory); };
	return !isPresent;
}

bool Database::removeCategory(std::string category) {
	int position = positionOnCatList(category);
	if (position >= 0) {
		remove(filter(listOfAccounts, 3, category));
		listOfCategories.erase(listOfCategories.begin() + position);
		return true;
	}
	else return false;
}

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

Account* Database::find(std::string name) {
	auto db = this->getDbPtr();
	std::vector<Account> guwno = *db;
	//int i = 0;
	//for (auto& account : guwno)
	//{
	//	if (account.getName() == name) { i = account; }
	//}
	return &db->at(2);
}

size_t Database::passUses(std::string pass) const {
	size_t uses = 0;
	auto db = this->getDb();
	for (auto account : db)
	{
		if (account.getPass() == pass) { uses++; }
	}
	return uses;
}

void Database::print(std::vector<Account> listAcc){
	for (Account acc : listAcc)	{acc.print();}
}

void Database::add(const Account& account) {
	if (!isPresent(account.getName())) {
		listOfAccounts.push_back(account);
		//std::cout << "Konto : " << account.getName() << " - dopisane" << std::endl;
	}
	else { std::cout << "Konto : " << account.getName() << " juz istnieje" << std::endl;
	}
	addCategory(account.getCategory());
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

std::vector<Account> Database::filter(std::vector<Account> listAcc, size_t filter, std::string val) {
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

void Database::remove(std::vector<Account> listAcc) {
	for (Account acc : listAcc)
	{
		auto it = listOfAccounts.begin()+position(acc.getName());
		if (it != listOfAccounts.end()) {
			std::cout << "Usuwam konto : " << acc.getName() << std::endl;
			listOfAccounts.erase(it);
		}
	}
}

void Database::sortIt(size_t firstFilter, size_t secondFilter) {
	size_t collection_to_loop []  = {firstFilter, secondFilter};
	for (size_t var : collection_to_loop)
	{
		switch (var)
		{
		case 1: std::sort(listOfAccounts.begin(), listOfAccounts.end(), [](Account x, Account y)
			{
				return x.getName().compare(y.getName()) < 0;
			});
		case 2: std::sort(listOfAccounts.begin(), listOfAccounts.end(), [](Account x, Account y)
			{
				return x.getPass().compare(y.getPass()) < 0;
			});
		case 3: std::sort(listOfAccounts.begin(), listOfAccounts.end(), [](Account x, Account y)
			{
				return x.getCategory().compare(y.getCategory()) < 0;
			}); 
		case 4: std::sort(listOfAccounts.begin(), listOfAccounts.end(), [](Account x, Account y)
			{
				return x.getLogin().compare(y.getLogin()) < 0;
			});
		case 5: std::sort(listOfAccounts.begin(), listOfAccounts.end(), [](Account x, Account y)
			{
				return x.getWebsite().compare(y.getWebsite()) < 0;
			});
		default: break;
		}
	}
}




