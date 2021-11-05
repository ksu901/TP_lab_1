#pragma once
#include "Base.h"
class Poet :
    public Base
{
private:
    string FIO, liveYears;
	string* works;
	int countWorks;
public:
	Poet();
	Poet(string FIO, string liveYears, string* works, int countWorks);
	Poet(const Poet& poet);
	~Poet();

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();

	string getFIO() { return FIO; }
	void setFIO(string FIO) { this->FIO = FIO; }

	string getLiveYears() { return liveYears; }
	void setLiveYears(string liveYears) { this->liveYears = liveYears; }

	string* getWorks() { return works; }
	int geCountWorks() { return countWorks; }
	void setWorks(string* works, int countWorks);

};

