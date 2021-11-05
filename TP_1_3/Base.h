#pragma once
#include "helper.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Base
{
private:
	string typeObj;
public:
	Base(string typeObj);
	Base(const Base& base);
	~Base() { cout << "Вызван деструктор Base" << endl; }

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change() = 0;

	bool operator>(const Base& base);

	string getTypeObj() { return typeObj; }
	void setTypeObj(string typeObj) { this->typeObj = typeObj; }
};

