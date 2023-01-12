#include "menu.hpp"

using namespace formatVariables;

bool Menu::hello(Database &db) {
	bool validated = false;
	std::string pass, newPath;
	std::string path = "dirMithran.txt";
	std::cout << "    Podaj nazwe  pliku do wczytania danych, lub wpisz : " << std::endl;
	std::cout << "0 - By uzyc pliku domyslnego : " << path << std::endl;
	std::cout << "1 - By zaczac bez pliku :" << std::endl;
	std::cin >> newPath;


	if (newPath == "1"){
		newPath = Menu::getLimitedString("Podaj nazwe nowego pliku :");
		path = txtSufix(newPath);
		pass = Menu::getLimitedString("Podaj haslo do nowego pliku :");
	}
	else 
	{
		if (newPath != "0") {
			while (!isFilePresent(txtSufix(newPath))) { std::cout << "Bledna sciezka do pliku, podaj inna :" << std::endl; std::cin >> newPath; }
			path = txtSufix(newPath);
		}
	}

	bool pathFound = isFilePresent(path);
	if (pathFound)
	{
		while (!validated) {
			std::cout << "Podaj haslo : " << std::endl;
			std::cin >> pass;
			int records = 0, categories = 0;
			validated = Open::validate(path, pass);
			if (validated) {
				std::cout << "podano poprawne haslo" << std::endl;
				Open::read(db, path, pass);
			}
			else {
				std::string timeStmp = __TIMESTAMP__;
				std::cout << timeStmp << std::endl;
				Save::nastyAccesSave(pass, path, timeStmp);
				std::cout << "Podano bledne haslo" << std::endl;
			}
		}
	}

	bool exit = false;
	std::string stop;
	while (!exit) {
		exit = main(db, pass, path);;
	}
	if (validated) { Menu::save(db, pass, path); }
	return validated;
}

bool Menu::main(Database &db, std::string & pass, std::string& path) {
	bool exit = false;
	std::string val;
	std::cout << " 0 - wyjdz i zapisz" << std::endl;
	std::cout << " 1 - dodaj rekord" << std::endl;
	std::cout << " 2 - edytuj rekord" << std::endl;
	std::cout << " 3 - wyfiltruj i pokaz rekordy" << std::endl;
	std::cout << " 4 - posortuj i pokaz rekordy" << std::endl;
	std::cout << " 5 - usun wybrane rekordy" << std::endl;
	std::cout << " 6 - dodaj kategorie" << std::endl;
	std::cout << " 7 - usun kategorie" << std::endl;
	std::cout << " 8 - wyswietl kategorie" << std::endl;
	std::cout << " 9 - zmien haslo" << std::endl;
	std::cout << "10 - zmien sciezke" << std::endl;
	std::cout << "11 - zapisz" << std::endl;
	std::cout << std::endl;
	std::cin >> val;
	std::cout << std::endl;

	switch (stoi(val))
	{
	case 0: exit = true; break;
	case 1:	addRecord(db); break;
	case 2:	editRecord(db);	break;
	case 3:	filterRecords(db); break;
	case 4:	sortRecords(db); break;
	case 5:	removeRecords(db); break;
	case 6:	addCategory(db); break;
	case 7:	removeCategory(db); break;
	case 8:	printCategorys(db); break;
	case 9:	changePass(pass); break;
	case 10: changePath(path); break;
	case 11: save(db, pass, path); break;
	default: std::cout << "Podales bledna wartosc" << std::endl; break;
	}
	return exit;
}

void Menu::addRecord(Database &db) {
	std::string name, pass, category, website, login, categoryNext;
	bool correct = false;
	std::cout << "Podaj nazwe : " << std::endl;
	std::cin >> name;
	pass = addPass();
	std::cout << "Dotychasowa ilosc uzyc hasla : " << db.passUses(pass) << std::endl;
	PassRandomizer::ratePassSafty(pass);
	std::cout << "Podaj kategorie : " << std::endl;
	std::cin >> category;
	correct = db.isOnCatList(category);
	while (!correct) {
		db.printCategorys();
		std::cout << "Tej kategorii jeszcze nie ma, wpisz 0 by dodac lub wybierz jedna z powyzszych" << std::endl;
		std::cin >> categoryNext;
		if (categoryNext == "0") { correct = true; }
		else {
			correct = db.isOnCatList(categoryNext);
			category = categoryNext;
		}
	}
	std::cout << "Podaj strone | 0 dla pustego : " << std::endl;
	std::cin >> website;
	std::cout << "Podaj login | 0 dla pustego : " << std::endl;
	std::cin >> login;

	website = website == "0" ? "\0" : website;
	login = login == "0" ? "\0" : login;
	db.add(Account(name, pass, category, website, login));
}

void Menu::editRecord(Database& db)
{
	std::string name, field, newVal;
	bool exit = false;
	bool correctName = false;
	while (!correctName) {
		std::cout << "Podaj nazwe rekordu lub 0 by wyjsc : " << std::endl;
		std::cin >> name;
		correctName = db.isPresent(name);
		if (name == "0") { exit = true; break; }
		if (!correctName) { std::cout << "Podana niepoprawna nazwe" << std::endl; }
	}
	if (exit == false) {
		
			std::cout << "0 - Wyjdz : " << std::endl;
			std::cout << "1 - Nazwa : " << std::endl;
			std::cout << "2 - Haslo : " << std::endl;
			std::cout << "3 - Kategoria : " << std::endl;
			std::cout << "4 - Strona : " << std::endl;
			std::cout << "5 - Login : " << "\n";					
				
		std::cout << "Podaj pole do edycji - liczba : " << "\n";
		std::cin >> field;
			
		newVal = getLimitedString("Podaj nowa wartosc : ");
		exit = switchEdit(db, name, field, newVal);
	}
};

void Menu::removeRecords(Database &db) {
	std::vector<Account> listAcc;
	std::cout << "Usuwanie wyfiltrowanej grupy rekordow" << std::endl;
	std::cout << "Podaj ilosc filtrow | 0 by usunac wszystko" << std::endl;
	listAcc = listRecords(db);
	db.remove(listAcc);
};

void Menu::sortRecords(Database &db) {
	db.sortIt(3, 1);
	Database::print(db.getDb());
};

void Menu::filterRecords(Database& db) {
	std::vector<Account> listAcc;
	std::cout << "Podaj ilosc filtrow | 0 by pokazac wszystko" << std::endl;
	listAcc = listRecords(db);
	Database::print(listAcc);
};

void Menu::addCategory(Database& db) {
	std::string name;
	name = getLimitedString("Podaj nazwe kategorii do dodania : ");
	if (!db.addCategory(name)){ std::cout << "!!! Taka kategoria juz jest !!!" << std::endl; } ;
};

void Menu::removeCategory(Database& db) {
	std::string name;
	std::cout << "Podaj nazwe kategorii do usuniecia : " << std::endl;
	std::cin >> name;
	if (!db.removeCategory(name)) { std::cout << "!!! Nie ma takiej kategorii !!!" << std::endl; };
}

void Menu::printCategorys(Database& db) {
	db.printCategorys();
}

void Menu::changePass(std::string &pass) {
	std::string newPass;
	std::cout << "Podaj nowe haslo : " << std::endl;
	std::cin >> newPass;	
	std::cout << "Nowe haslo to : " << newPass << std::endl;
	pass = newPass;
}

void Menu::changePath(std::string& path)
{
	std::string newPath;
	std::cout << "Aktualna sciezka to : " << path << std::endl;
	std::cout << "Podaj nowa sciezke : " << std::endl;
	std::cin >> newPath;
	path = txtSufix(newPath);
	std::cout << "Nowa sciezka to : " << path << std::endl;
}

void Menu::save(Database& db, std::string pass, std::string path) {
	std::cout << "Zapisywanie" << std::endl;
	Save::saveAll(db, path, pass);
	std::cout << "Zapisano" << std::endl;
}

std::vector<Account> Menu::listRecords(Database& db) {
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

		filter = getLimitedValue("",10);
		val = getLimitedString("Podaj wartosc");

		listAcc = Database::filter(listAcc, filter, val);
	}
	return listAcc;
}

std::string Menu::addPass() {
	std::string pass;

	std::cout << "Podaj haslo | 0 dla generowania hasla : " << std::endl;
	std::cin >> pass;
	if (pass == "0") { pass = PassRandomizer::randPass(); }
	return pass;
}

bool Menu::switchEdit(Database& db, std::string const name, std::string const field, std::string const newVal) {
	bool exit = false;
	Account* acc = db.find(name);
	switch (stoi(field)) {
	case 0:	exit = true; break;
	case 1: acc->setName(newVal); break;
	case 2: acc->setPass(newVal); break;
	case 3: acc->setCategory(newVal); break;
	case 4: acc->setWebsite(newVal); break;
	case 5: acc->setLogin(newVal); break;
	default: std::cout << "Podales bledna wartosc pola" << std::endl; break;
	}
	return exit;
}

std::string Menu::getLimitedString(const std::string credits) {
	std::string stringIn;
	size_t size = limit;
	while (size >= limit) {
		std::cout << "Tekst nie moze byc dluzszy niz " << limit << " znakow" << std::endl;
		std::cout << credits << std::endl;
		std::cin >> stringIn;
		size = stringIn.length();
	}
	return stringIn;
}

size_t Menu::getLimitedValue(const std::string  credits, const size_t max) {
	std::string stringIn;
	size_t value = max+1;
	while (value > max) {
		std::cout << credits << std::endl;
		std::cin >> stringIn;
		try
		{
			value = stoi(stringIn);
		}
		catch (const std::exception&)
		{
			std::cout << "!!!Nie podano liczby!!!" << std::endl;
		}		
		if (value>max){ std::cout << "Liczba spoza oczekiwanych wartosci" << std::endl; }
	}
	return value;
}

bool Menu::isFilePresent(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

std::string Menu::txtSufix(std::string path) {
	if (!(path.find(".txt") == path.length() - 4)) {
		path.append(".txt");
	}
	return path;
}
