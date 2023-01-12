#include "open.hpp"

using namespace formatVariables;

std::vector<std::string> Open::getAll(const std::string &path)
{
	std::vector<std::string> allLines;
	std::fstream file;
	file.open(path,std::ios::in);
	std::string line;
	int i = 0;
	while (std::getline(file, line)) {
		allLines.push_back(line);
	}
	file.close();
	return allLines;
}

bool Open::validate(const std::string &path, const std::string &pass) {
	std::vector<std::string> allLines = Open::getAll(path);
	std::string checkLine = allLines[margin-1];
	int size = (checkLine[limit +2] - checkLine[limit + 1]);
	int marker = 0;
	try
	{
		marker = stoi(Open::decipher(checkLine, pass));
	}
	catch (const std::exception&)
	{
		std::cout << "!!!Nieudana proba dekrypcji!!!" << std::endl;
	}
	return (size == 5) && (marker >= 10000);
}

std::string Open::decipher(const std::string &line) {
	std::string text;
	int shift, size;
	shift = line[limit + 2] - line[limit + 1];
	size = shift > 0 ? shift : shift + omega - alfa;
		if (size != 32) {
		for (size_t i = 0; i < size; i++)
		{
			int sign, hornet = alfa + line[i] - line[beta - 1 - i];
			if (hornet < alfa || hornet > omega) { sign = (hornet + omega - alfa); }
			else { sign = hornet; }
			text.push_back(sign);
		}
		return text;
	}
	else return "0";
}
std::string Open::decipher(const std::string &line, const std::string &pass) {
	std::string text;
	int shift, size;
	shift = line[limit + 2] - line[limit + 1];
	size = shift > 0 ? shift : shift + omega - alfa;
	if (size != 32) {
		for (size_t i = 0; i < size; i++)
		{
			int sign, hornet, passHornet;
			passHornet = pass[i % pass.length()] % alfa;
			hornet = alfa + passHornet + line[i] - line[beta - 1 - i];
			if (hornet < alfa || hornet > omega) { sign = (hornet + omega - alfa); }
			else { sign = hornet; }
			text.push_back(sign);

		}
		return text;
	}
	else return "0";
}

std::vector<std::string>  Open::decodeAll(const std::string &path, int &records, int &categories, const std::string &pass) {
	std::vector<std::string> encryptedLines = Open::getAll(path);
	std::vector<std::string> decodedLines;
	if (true) {
		if (encryptedLines[margin - 3][limit + 2] - encryptedLines[margin - 3][limit + 1] == 24) {
			std::cout << "!!! OSTATNIO MIALA MIEJSCE NIEUDANA PROBA LOGOWANIA !!!" << std::endl;
			std::cout << "Dnia : " << decipher(encryptedLines[margin - 3]) << std::endl;
			std::cout << "Podano bledne haslo : " << decipher(encryptedLines[margin - 4]) << std::endl;
		}
		records = stoi(decipher(encryptedLines[margin - 2], pass));
		categories = stoi(decipher(encryptedLines[margin - 1], pass))-10000;
		for (size_t i = margin; i < records*5+margin+categories; i++)
		{
			decodedLines.push_back(decipher(encryptedLines[i], pass));
		}
	}
	return decodedLines;
}

void Open::read(Database &db, const std::string &path, const std::string &pass) {
	int records;
	int categories;

	std::vector<std::string> decodedLines = Open::decodeAll( path, records,categories, pass);
	for (size_t i = 0; i < records; i++)
	{
		std::string	name,pass,category,website,login;
		size_t loop = i * 5;
		name = decodedLines[loop];
		pass = decodedLines[loop + 1];
		category = decodedLines[loop + 2];
		website = decodedLines[loop + 3];
		login = decodedLines[loop + 4];
		Account acc = Account(name,pass,category,website,login);
		db.add(acc);
	}
	for (size_t i = records*5; i < records*5+categories; i++)
	{
		db.addCategory(decodedLines[i]);
	}
}
