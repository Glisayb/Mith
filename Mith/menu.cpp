#include "menu.hpp"
#include "passRandomizer.hpp"

void Menu::hello(Database &db) {
	bool correct = false;
	std::string pass;
	while (!correct) {
		std::cout << "Podaj haslo : " << std::endl;
		std::cin >> pass;
		if (pass == "maslo") {
			std::cout << "Podano poprawne haslo" << std::endl;
			correct = true;
		}
		else {
			std::cout << "Podano bledne haslo" << std::endl;
		}
	}

	bool exit = false;
	std::string stop;
	while (!exit) {
		exit = main(db);;
	}
}

bool Menu::main(Database &db) {
	bool exit = false;
	std::string val;
	std::cout << "0 - wyjscie" << std::endl;
	std::cout << "1 - dodanie rekordu" << std::endl;
	std::cout << "2 - edycja rekordu" << std::endl;
	std::cout << "3 - wyfiltruj i pokaz" << std::endl;
	std::cout << "4 - dodaj kategorie" << std::endl;
	std::cout << "5 - " << std::endl;
	std::cout << "6 - wyswietl kategorie" << std::endl;
	std::cout << std::endl;
	std::cin >> val;
	std::cout << std::endl;

	switch (stoi(val))
	{
	case 0: exit = true; break;
	case 1:	addRecord(db); break;
	case 2:	editRecord(db);	break;
	case 3:	filterRecords(db); break;
	case 4:	addCategory(db); break;
	case 6:	db.printCategorys(); break;
	default: std::cout << "Podales bledna wartosc" << std::endl; break;
	}
	return exit;
}

void Menu::addCategory(Database& db) {
	std::string name;
	std::cout << "Podaj nazwe kategorii do dodania : " << std::endl;
	std::cin >> name;
	db.addCategory(name);
};

void Menu::addRecord(Database &db) {
	std::string name, pass, category, website, login;
	std::cout << "Podaj nazwe : " << std::endl;
	std::cin >> name;
	pass = passAdding();
	Account::howPassSafe(pass);
	std::cout << "Podaj kategorie : " << std::endl;
	std::cin >> category;
	std::cout << "Podaj strone | 0 dla pustego : " << std::endl;
	std::cin >> website;
	std::cout << "Podaj login | 0 dla pustego : " << std::endl;
	std::cin >> login;

	website = website == "0" ? "/" : website;
	login = login == "0" ? "/" : login;
	db.add(Account(name, pass, category, website, login));
}

void Menu::editRecord(Database &db)
{
	std::string name, field, newVal;
	bool exit = false;
	{
		{ 
			{
			std::cout << "Podaj nazwe rekordu : " << std::endl;
			std::cin >> name;

			std::cout << "0 - Wyjdz : " << std::endl;
			std::cout << "1 - Nazwa : " << std::endl;
			std::cout << "2 - Haslo : " << std::endl;
			std::cout << "3 - Kategoria : " << std::endl;
			std::cout << "4 - Strona : " << std::endl;
			std::cout << "5 - Login : " << "\n";
		}
	std::cout << "Podaj pole do edycji - liczba : " << "\n";
	std::cin >> field;
	}
	std::cout << "Podaj nowa wartosc : " << "\n";
	std::cin >> newVal; }
	exit = switchEdit(db, name, field, newVal);			
}

std::vector<Account> listRecords(Database &db){
	std::vector<Account> listAcc = db.getDb();
	size_t i, filter;
	std::string val;
	std::cin >> i;
	for (size_t j = 0; j < i; j++)
	{
		std::cout << "1 | 6 - Nazwa" << std::endl;
		std::cout << "2 | 7 - Haslo" << std::endl;
		std::cout << "3 | 8 - Kategoria" << std::endl;
		std::cout << "4 | 9 - Strona" << std::endl;
		std::cout << "5 | 10 - Login" << std::endl;
		std::cout << "Wybierz " << j + 1 << " filtr | +5 dla wartosci wzglednych :" << std::endl;
		std::cin >> filter;
		std::cout << "Podaj wartosc" << std::endl;
		std::cin >> val;

		listAcc = Database::filter(listAcc, filter, val);
	}
	return listAcc;
}

void Menu::removeRecords(Database &db) {
	std::vector<Account> listAcc;
	std::cout << "Usuwanie wyfiltrowanej grupy rekordow" << std::endl;
	std::cout << "Podaj ilosc filtrow" << std::endl;
	listAcc = listRecords(db);
	db.remove(listAcc);
};
void Menu::sortRecords(Database &db) {};
void Menu::filterRecords(Database &db) {
	std::vector<Account> listAcc;
		std::cout << "Podaj ilosc filtrow" << std::endl;
		listAcc = listRecords(db);
	Database::print(listAcc);
}

std::string Menu::passAdding() {
	std::string pass;

	std::cout << "Podaj haslo | 0 dla generowania hasla : " << std::endl;
	std::cin >> pass;
	if (pass == "0") {
		std::string length, capitals, specials, letPrint;

		std::cout << "Podaj dlugosc : " << std::endl;
		std::cin >> length;
		std::cout << "Podaj ilosc wielkich liter : " << std::endl;
		std::cin >> capitals;
		std::cout << "Podaj ilosc znakow specjalnych : " << std::endl;
		std::cin >> specials;

		pass = PassRandomizer::randPass(stoi(length), stoi(capitals), stoi(specials));

		std::cout << "Jesli chcesz zobaczyc haslo na ekranie wpisz 0 : " << std::endl;
		std::cin >> letPrint;

		if (letPrint == "0")
		{
			std::cout << "Twoje haslo to : " << pass << std::endl;
		}
	}
	return pass;
}

bool Menu::switchEdit(Database& db, std::string name, std::string field, std::string newVal) {
	bool exit = false;
	switch (stoi(field)) {
	case 0:	exit = true; break;
	case 1: db.find(name)->setName(newVal); break;
	case 2: db.find(name)->setPass(newVal); break;
	case 3: db.find(name)->setCategory(newVal); break;
	case 4: db.find(name)->setWebsite(newVal); break;
	case 5: db.find(name)->setLogin(newVal); break;
	default: std::cout << "Podales bledna wartosc pola" << std::endl; break;
	}
	return exit;
}