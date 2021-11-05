#include "Romantic.h"

Romantic::Romantic() : Poet(), biography("�� ������")
{
	setTypeObj("���������");
	cout << "������ ����������� Romantic" << endl;
}

Romantic::Romantic(string FIO, string liveYears, string* works, int countWorks, string biography) :
	Poet(FIO, liveYears, works, countWorks), biography(biography)
{
	setTypeObj("���������");
	cout << "������ ����������� Romantic" << endl;
}

Romantic::Romantic(const Romantic& romantic) :
	Poet(romantic), biography(romantic.biography)
{
	cout << "������ ����������� ����������� Romantic" << endl;
}

void Romantic::inputFromConsole()
{
	Poet::inputFromConsole();
	cout << "������� ���������: ";
	getline(cin, biography);
}

void Romantic::inputFromFile(std::ifstream& file, std::string& tmpS)
{
	Poet::inputFromConsole();
	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	biography = tmpS;
}

void Romantic::printToConsole()
{
	Poet::printToConsole();
	cout << "���������: " << biography << endl;
}

void Romantic::printToFile(ostream& out)
{
	Poet::printToFile(out);
	out << biography << endl;
}

void Romantic::change()
{
	Poet::change();
	cout << "������� ����� ���������: ";
	getline(cin, biography);
}