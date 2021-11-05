#pragma once
#include "Poet.h"

class Romantic :
    public Poet
{
private:
	string biography;
public:
	Romantic();
	Romantic(string FIO, string liveYears, string* works, int countWorks, string biography);
	Romantic(const Romantic& romantic);
	~Romantic() { cout << "Вызван деструктор Romantic" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getBiography() { return biography; }
	void setBiography(string biography) { this->biography = biography; }
};

