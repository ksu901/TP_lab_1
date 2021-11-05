#include "Poet.h"

Poet::Poet() : Base("Поэт"), FIO("Не задано"), liveYears("Не задано"), works(nullptr), countWorks(0)
{
	cout << "Вызван конструктор Poet" << endl;
}

Poet::Poet(string FIO, string liveYears, string* works, int countWorks) :
	Base("Поэт"), FIO(FIO), liveYears(liveYears)
{
	setWorks(works, countWorks);
	cout << "Вызван конструктор Poet" << endl;
}

Poet::Poet(const Poet& poet) :
	Base(poet), FIO(poet.FIO), liveYears(poet.liveYears)
{
	setWorks(poet.works, poet.countWorks);
	cout << "Вызван конструктор копирования Poet" << endl;
}

Poet::~Poet()
{
	delete[] works;
	works = nullptr;
	cout << "Вызван деструктор Poet" << endl;
}

void Poet::setWorks(string* works, int countWorks) {
	this->countWorks = countWorks;
	this->works = new string[countWorks];
	for (int i = 0; i < countWorks; i++)
		this->works[i] = works[i];
}

void Poet::inputFromConsole()
{
	cout << "Введите ФИО: ";
	getline(cin, FIO);
	cout << "Введите годы жизни: ";
	liveYears = inputLiveYears();
	cout << "Введите количество произведений: ";
	countWorks = safeInput(1, INT32_MAX);
	works = new string[countWorks];
	for (int i = 0; i < countWorks; i++) {
		cout << "Введите " << i + 1 << " произведение: ";
		getline(cin, works[i]);
	}
}

void Poet::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "Файл не может быть корректно прочитан";
	if (!getline(file, tmpS))
		throw err;
	FIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	liveYears = (checkStringToLiveYears(tmpS) ? tmpS : "Не задано");
	if (!getline(file, tmpS))
		throw err;
	countWorks = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	works = new string[countWorks];
	for (int i = 0; i < countWorks; i++) {
		if (!getline(file, tmpS))
			throw err;
		works[i] = tmpS;
	}
}

void Poet::printToConsole()
{
	Base::printToConsole();
	cout << "ФИО: " << FIO << endl;
	cout << "Годы жизни: " << liveYears << endl;
	if (countWorks > 0) {
		cout << "Список произведений:" << endl;
		for (int i = 0; i < countWorks; i++)
			cout << i + 1 << ". " << works[i] << endl;
	}
	else
		cout << "Способностей нет" << endl;
}

void Poet::printToFile(ostream& out)
{
	Base::printToFile(out);
	out << FIO << endl;
	out << liveYears << endl;
	out << countWorks << endl;
	for (int i = 0; i < countWorks; i++)
		out << works[i] << endl;
}

void Poet::change()
{
	cout << "Введите новое ФИО: ";
	getline(cin, FIO);
	cout << "Введите новые годы жизни: ";
	liveYears = inputLiveYears();
	cout << "Введите новое количество произведений: ";
	countWorks = safeInput(1, INT32_MAX);
	works = new string[countWorks];
	for (int i = 0; i < countWorks; i++) {
		cout << "Введите " << i + 1 << " произведение: ";
		getline(cin, works[i]);
	}
}