#include "Fantasist.h"

Fantasist::Fantasist() : Poet(), isMovening(false)
{
	setTypeObj("Фантаст");
	cout << "Вызван конструктор Fantasist" << endl;
}

Fantasist::Fantasist(string FIO, string liveYears, string* works, int countWorks, bool isMovening) :
	Poet(FIO, liveYears, works, countWorks), isMovening(isMovening)
{
	setTypeObj("Фантаст");
	cout << "Вызван конструктор Fantasist" << endl;
}

Fantasist::Fantasist(const Fantasist& fantasist) :
	Poet(fantasist), isMovening(fantasist.isMovening)
{
	cout << "Вызван конструктор копирования Fantasist" << endl;
}

void Fantasist::inputFromConsole()
{
	Poet::inputFromConsole();
	cout << "Сняты ли фильмы по книгам?(1/0): ";
	isMovening = safeInput(0, 1);
}

void Fantasist::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Poet::inputFromConsole();
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	isMovening = (checkStringToInt(tmpS) && (tmpS == "1" || tmpS == "0") ? tmpS[0] : 0);
}

void Fantasist::printToConsole()
{
	Poet::printToConsole();
	if (isMovening)
		cout << "По книгам сняты фильмы" << endl;
	else
		cout << "По книгам не сняты фильмы" << endl;
}

void Fantasist::printToFile(ostream& out)
{
	Poet::printToFile(out);
	out << isMovening << endl;
}

void Fantasist::change()
{
	Poet::change();
	cout << "Сняты ли фильмы по книгам?(1/0): ";
	isMovening = safeInput(0, 1);
}