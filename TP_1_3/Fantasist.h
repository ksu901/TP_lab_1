#pragma once
#include "Poet.h"
class Fantasist :
    public Poet
{
private:
	bool isMovening;
public:
	Fantasist();
	Fantasist(string FIO, string liveYears, string* works, int countWorks, bool isMovening);
	Fantasist(const Fantasist& fantasist);
	~Fantasist() { cout << "Вызван деструктор Fantasist" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	bool getName() { return isMovening; }
	void setName(bool isMovening) { this->isMovening = isMovening; }
};

