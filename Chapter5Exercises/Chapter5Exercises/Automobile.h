#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <time.h>
using namespace std;

class Automobile
{
public:
	Automobile();
	Automobile(string newManufacturer, string newModel, int newYear);
	~Automobile();
	void setManufacturer(string newManufacturer);
	string getManufacturer();
	void setModel(string newModel);
	string getModel();
	void setYear(int newYear);
	int getYear();
	string fullDescription();
	int automobileAge();
private:
	string manufacturer;
	string model;
	int year;
};