#include "Poet.h"

Poet::Poet() : Base("����"), FIO("�� ������"), liveYears("�� ������"), works(nullptr), countWorks(0)
{
	cout << "������ ����������� Poet" << endl;
}

Poet::Poet(string FIO, string liveYears, string* works, int countWorks) :
	Base("����"), FIO(FIO), liveYears(liveYears)
{
	setWorks(works, countWorks);
	cout << "������ ����������� Poet" << endl;
}

Poet::Poet(const Poet& poet) :
	Base(poet), FIO(poet.FIO), liveYears(poet.liveYears)
{
	setWorks(poet.works, poet.countWorks);
	cout << "������ ����������� ����������� Poet" << endl;
}

Poet::~Poet()
{
	delete[] works;
	works = nullptr;
	cout << "������ ���������� Poet" << endl;
}

void Poet::setWorks(string* works, int countWorks) {
	this->countWorks = countWorks;
	this->works = new string[countWorks];
	for (int i = 0; i < countWorks; i++)
		this->works[i] = works[i];
}

void Poet::inputFromConsole()
{
	cout << "������� ���: ";
	getline(cin, FIO);
	cout << "������� ���� �����: ";
	liveYears = inputLiveYears();
	cout << "������� ���������� ������������: ";
	countWorks = safeInput(1, INT32_MAX);
	works = new string[countWorks];
	for (int i = 0; i < countWorks; i++) {
		cout << "������� " << i + 1 << " ������������: ";
		getline(cin, works[i]);
	}
}

void Poet::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	FIO = tmpS;
	if (!getline(file, tmpS))
		throw err;
	liveYears = (checkStringToLiveYears(tmpS) ? tmpS : "�� ������");
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
	cout << "���: " << FIO << endl;
	cout << "���� �����: " << liveYears << endl;
	if (countWorks > 0) {
		cout << "������ ������������:" << endl;
		for (int i = 0; i < countWorks; i++)
			cout << i + 1 << ". " << works[i] << endl;
	}
	else
		cout << "������������ ���" << endl;
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
	cout << "������� ����� ���: ";
	getline(cin, FIO);
	cout << "������� ����� ���� �����: ";
	liveYears = inputLiveYears();
	cout << "������� ����� ���������� ������������: ";
	countWorks = safeInput(1, INT32_MAX);
	works = new string[countWorks];
	for (int i = 0; i < countWorks; i++) {
		cout << "������� " << i + 1 << " ������������: ";
		getline(cin, works[i]);
	}
}