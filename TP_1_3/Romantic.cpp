#include "Romantic.h"

Romantic::Romantic() : Poet(), biography("Не задано")
{
	setTypeObj("Романтист");
	cout << "Вызван конструктор Romantic" << endl;
}

Romantic::Romantic(string FIO, string liveYears, string* works, int countWorks, string biography) :
	Poet(FIO, liveYears, works, countWorks), biography(biography)
{
	setTypeObj("Романтист");
	cout << "Вызван конструктор Romantic" << endl;
}

Romantic::Romantic(const Romantic& romantic) :
	Poet(romantic), biography(romantic.biography)
{
	cout << "Вызван конструктор копирования Romantic" << endl;
}

void Romantic::inputFromConsole()
{
	Poet::inputFromConsole();
	cout << "Введите биографию: ";
	getline(cin, biography);
}

void Romantic::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Poet::inputFromConsole();
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	biography = tmpS;
}

void Romantic::printToConsole()
{
	Poet::printToConsole();
	cout << "Биография: " << biography << endl;
}

void Romantic::printToFile(ostream& out)
{
	Poet::printToFile(out);
	out << biography << endl;
}

void Romantic::change()
{
	Poet::change();
	cout << "Введите новую биографию: ";
	getline(cin, biography);
}