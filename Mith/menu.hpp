#pragma once
#include <iostream>
#include <string>
#include "database.hpp"
#include "save.hpp"
#include "passRandomizer.hpp"
#include "open.hpp"

class Menu
{
private:
	Database db;
	std::string path;
	std::string pass;

public:
	/// <summary>obiekt pozwala rozpoczac nawigacje po aplikacji Mithrandir
	/// 
	/// </summary>
	/// <param name="path"></param>
	Menu(std::string path);
	/// <summary>menu powitalne, sprawdza haslo
	/// menu kaze sprawdza haslo i wczytuje zapisana baze, lub tworzy nowa i prosi o dodanie hasla
	/// </summary>
	/// <returns></returns>
	bool hello();
	/// <summary>podstawowe menu nawigacyjne
	/// menu pozwala nawigowac i wielokrotnie wykonywaz polecenia az do wywolania zadania zamkniecia
	/// </summary>
	/// <returns></returns>
	bool main();

	/// <summary>polecenie dodania rekordu
	/// 
	/// </summary>
	void addRecord();
	/// <summary>polecenie edycji rekordu
	/// 
	/// </summary>
	void editRecord();
	/// <summary>polecenie usuniecia rekordow
	/// usuwana jest lista rekordow pasujaca do dowolnej ilosci wybranych filtrow, pojedynczy rekord usunac mozna po nazwie
	/// </summary>
	void removeRecords();
	/// <summary>polecenie posortowania rekordow
	/// sortuje po dwoch wlasciwosciach i pokazuje rekordy na ekranie, dla pojedynczej wlasciwosci podajemy dwa razy to samo
	/// </summary>
	void sortRecords();
	/// <summary>polecenie wyfiltrowania rekordow
	/// filtruje rekordy po dowolnej ilosci wlasciwosci i pokazuje je na ekranie
	/// </summary>
	void filterRecords() const;

	/// <summary>polecenie dodania nowej kategorii
	/// 
	/// </summary>
	void addCategory();
	/// <summary>polecenie usuniecia kategorii
	/// usuwa kategorie wraz z przynaleznymi do niej wpisami
	/// </summary>
	void removeCategory();
	/// <summary>polecenie wyswietla liste kategorii
	/// 
	/// </summary>
	void printCategorys() const;

	/// <summary>polecenie zmienia haslo szyfrujace plik
	/// 
	/// </summary>
	void changePass();
	/// <summary>polecenie zmienia sciezke do zapisu pliku
	/// zmieniana jest sciezka ale zapis nie nastepuje samoczynnie
	/// </summary>
	void changePath();

	/// <summary>polecenie zapisuje plik
	/// 
	/// </summary>
	void save() const;

	/// <summary>zwraca liste o podanych wlasciwosciach
	/// 
	/// </summary>
	/// <returns></returns>
	std::vector<Account> listRecords() const;
	/// <summary>wywoluje wybrana przez uzytkownika funkcje edycji
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <param name="field"></param>
	/// <param name="newVal"></param>
	/// <returns></returns>
	bool switchEdit(const std::string& name, const std::string& field, const std::string& newVal);


	/// <summary>zleca dodanie hasla
	/// w zaleznosci od wyboru uzytkownika, wywoluje generator hasel lub dodaje haslo podane przez uzytkownika
	/// </summary>
	/// <returns></returns>
	static std::string addPass();

	/// <summary>broni przed podaniem niepozadanego lancucha znakow
	/// 
	/// </summary>
	/// <param name="credits">argument pozwala na wypisanie slow "zachety" dla uzytkownika</param>
	/// <returns></returns>
	static std::string getLimitedString(const std::string &credits);
	/// <summary>broni przed podaniem niepozadanego wartosci lub lancucha znakow
	/// 
	/// </summary>
	/// <param name="credits">argument pozwala na wypisanie slow "zachety" dla uzytkownika</param>
	/// <param name="max">argument pozwala na wprowadzenie limitu wartosci</param>
	/// <returns></returns>
	static size_t getLimitedValue(const std::string &credits, const size_t &max);
	/// <summary>sprawdza czy plik istnieje
	/// 
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	static bool isFilePresent(const std::string &name);
	/// <summary>sprawdza czy adres dostal sufix .txt
	/// jesli adres go nie ma to sufix zostanie dodany
	/// </summary>
	/// <param name="path"></param>
	/// <returns></returns>
	static std::string txtSufix(const std::string &path);
	static void print5opions();
};