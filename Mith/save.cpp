#include "save.hpp"

using namespace formatVariables;

char randSign() { return (((rand() % (omega - alfa))) + alfa); }
std::string randString(size_t size) {
	std::string buzz;
	for (size_t i = 0; i < size; i++)
	{		buzz.push_back(randSign());	}
	return buzz;
}

void Save::nastyAccesSave(std::string wrongPass, std::string path, std::string timeStmp) {
	std::vector<std::string> lines = Open::getAll(path);
	auto& timeLine = lines[margin-3];
	auto timeBuzzed = buzzing(timeStmp);
	timeLine = timeBuzzed;
	auto& passLine = lines[margin - 4];
	auto passBuzzed = buzzing(wrongPass);
	passLine = passBuzzed;
	std::ofstream file;
	file.open(path);
	for (std::string line : lines)
	{
		file << line << std::endl;
	}
	file.close();
}

std::string Save::buzzing(std::string getted) {

	size_t length = getted.length();
	int shifted;
	std::string buzz = randString(beta - length);

	std::string info = getted;
	std::string buzzed;

	for (size_t i = 0; i < length; i++)
	{
		int bee = info[i] + buzz[buzz.length() -1 - i]-alfa;
		if (bee > omega) { buzzed.push_back(bee - omega + alfa); }
		else { buzzed.push_back(bee); }
		std::cout << '|' << info[i] << '|' << (int)info[i] << '|' << (int)buzz[buzz.length() - 1 - i] << '|' << bee << '|' << (bee - omega + alfa) << '|' << std::endl;
	}
	buzzed.append(buzz);
	if (getted.empty()) { length = 32; }
	shifted = buzzed[limit + 1] + length;
	buzzed[limit+2] = shifted < omega ? shifted : (shifted - omega + alfa);
	return buzzed;
}

std::string Save::buzzing(std::string getted, std::string pass) {

	size_t length = getted.length();
	int shifted;
	std::string buzz = randString(beta - length);

	std::string info = getted;
	std::string buzzed;

	for (size_t i = 0; i < length; i++)
	{
		int passBee = pass[i % pass.length()] % alfa;
		int bee = info[i] + buzz[buzz.length() - 1 - i] - alfa - passBee;
		if (bee > omega) { buzzed.push_back(bee - omega + alfa); }
		else { buzzed.push_back(bee); }
		std::cout << '|' << info[i] << '|' << (int)info[i] << '|' << (int)buzz[buzz.length() - 1 - i] << '|' << bee << '|' << (bee - omega + alfa) << '|' << std::endl;
	}
	buzzed.append(buzz);
	if (getted.empty()) { length = 32; }
	shifted = buzzed[limit + 1] + length;
	buzzed[limit + 2] = shifted < omega ? shifted : (shifted - omega + alfa);
	return buzzed;
}


void Save::saveAll(Database db, std::string path, std::string pass)
{
	size_t catSize = db.getCat().size();
	std::ofstream file;
	file.open(path);
	for (size_t i = 0; i < margin-2; i++)
	{
		file << randString(beta) << std::endl;
	}
	file << buzzing(std::to_string(db.getDb().size()), pass) << std::endl;
	file << buzzing(std::to_string(catSize+10000),pass) << std::endl;
	for (Account acc : db.getDb())
	{
		file << buzzing(acc.getName(), pass) << std::endl;
		file << buzzing(acc.getPass(), pass) << std::endl;
		file << buzzing(acc.getCategory(), pass) << std::endl;
		file << buzzing(acc.getWebsite(), pass) << std::endl;
		file << buzzing(acc.getLogin(), pass) << std::endl;
	}
	for (std::string cat : db.getCat())
	{
		file << buzzing(cat, pass) << std::endl;
	}
	for (size_t i = 0; i < (margin/2-(catSize%10)); i++)
	{
		file << randString(beta) << std::endl;
	}
	file.close();
}
