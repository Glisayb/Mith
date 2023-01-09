#include "open.hpp"

using namespace formatVariables;

std::vector<std::string> Open::getAll(std::string path)
{
	std::vector<std::string> allLines;
	std::fstream file;
	file.open(path,std::ios::in);
	std::string line;

	while (std::getline(file, line)) {
		allLines.push_back(line);
	}
	file.close();
	return allLines;
}

bool Open::validate(std::string checkLine, std::string pass) {
	int size = (checkLine[limit +2] - checkLine[limit + 1]);
	//int marker = (alfa + checkLine[0] - checkLine[beta - 1]);
	//char sign;

	//std::cout << marker << std::endl;

	//if (marker >= alfa) {
	//	sign = marker;
	//}
	//else { sign = (marker + omega); }
	//
	//std::cout << size << std::endl;
	//std::cout << sign << std::endl;
	int marker = stoi(Open::decipher(checkLine,pass));

	return (size == 5) && (marker >= 10000);
}
std::string Open::decipher(std::string line) {
	std::string text;
	int shift, size;
	shift = line[limit + 2] - line[limit + 1];
	size = shift > 0 ? shift : shift + omega - alfa;
	std::cout <<'|' << (int)line[limit + 2] <<'|' << (int)line[limit + 1] << '|' << shift << std::endl;
	if (size != 32) {
		for (size_t i = 0; i < size; i++)
		{
			int sign, hornet = alfa + line[i] - line[beta - 1 - i];
			std::cout << (int)line[i] << '|' << (int)line[beta - 1 - i] << '|' << hornet << '|' << hornet + omega - alfa << std::endl;
			if (hornet < alfa || hornet > omega) { sign = (hornet + omega - alfa); }
			else { sign = hornet; }
			std::cout << sign << std::endl;
			text.push_back(sign);
		}

		std::cout << text << std::endl;
		std::cout << std::endl;
		return text;
	}
	else return "0";
}
std::string Open::decipher(std::string line, std::string pass) {
	std::string text;
	int shift, size;
	shift = line[limit + 2] - line[limit + 1];
	size = shift > 0 ? shift : shift + omega - alfa;
	//std::cout <<'|' << (int)line[limit + 2] <<'|' << (int)line[limit + 1] << '|' << shift << std::endl;
	if (size != 32) {
		for (size_t i = 0; i < size; i++)
		{
			int sign, hornet, passHornet;
			passHornet = pass[i % pass.length()] % alfa;
			hornet = alfa + passHornet + line[i] - line[beta - 1 - i];
			//std::cout << (int)line[i] << '|' << (int)line[beta - 1 - i] << '|' << hornet << '|' << hornet + omega - alfa << std::endl;
			if (hornet < alfa || hornet > omega) { sign = (hornet + omega - alfa); }
			else { sign = hornet; }
			//std::cout << sign << std::endl;
			text.push_back(sign);

		}
		//std::cout << text << std::endl;
		//std::cout << std::endl;
		return text;
	}
	else return "0";
}

std::vector<std::string>  Open::decodeAll(std::string path, int &records, int &categories, std::string pass) {
	std::vector<std::string> encryptedLines = Open::getAll(path);
	std::vector<std::string> decodedLines;
	if (Open::validate(encryptedLines[margin - 1],pass)) {
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
void Open::read(Database &db, std::string path, std::string pass) {
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
		//std::cout << "dodano "<< i << " pozycje" << std::endl;
	}
	for (size_t i = records*5; i < records*5+categories; i++)
	{
		db.addCategory(decodedLines[i]);
		//std::cout << "dodano " << i << " kategorie" << std::endl;
	}
}
