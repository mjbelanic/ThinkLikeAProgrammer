#include "pch.h"
#include "Automobile.h"


Automobile::Automobile()
{
}

Automobile::Automobile(string newManufacturer, string newModel, int newYear)
{
	setManufacturer(newManufacturer);
	setModel(newModel);
	setYear(newYear);
}


Automobile::~Automobile()
{
}

void Automobile::setManufacturer(string newManufacturer)
{
	this->manufacturer = newManufacturer;
}

string Automobile::getManufacturer()
{
	return this->manufacturer;
}

void Automobile::setModel(string newModel)
{
	this->model = newModel;
}

string Automobile::getModel()
{
	return this->model;
}

void Automobile::setYear(int newYear)
{
	this->year = newYear;
}

int Automobile::getYear()
{
	return this->year;
}

string Automobile::fullDescription()
{
	return to_string(getYear()) + " " + getManufacturer() + " " + getModel();
}

int Automobile::automobileAge()
{
	int year = this->getYear();
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);
	int currentYear = TM.tm_year + 1900;
	return currentYear - year;
}
