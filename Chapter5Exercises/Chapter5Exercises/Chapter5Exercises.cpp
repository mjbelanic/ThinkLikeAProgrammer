#include "pch.h"
#include "Automobile.h"
#include "VarLenString.h"
#include "StudentRecords.h"
#include <iostream>
#include <string>

using namespace std;

void exercise52();
void exercise53();
void exercise57();

int main()
{
	// Exercise 5-1 is to create the automobile class. (See Automobile.cpp / Automobile.h)
	//exercise52();
	// Exercises 5-3 through 5-6 all relate to creating the Variable Length String Class. 
	// This includes all supporting methods. (See VarLenString.cpp / VarLenString.h)
	//exercise53();
	// Exercises 5-7 and 5-8 all relate to creating the Student Records Class. 
	// This includes all supporting methods. (See StudentRecords.cpp / StudentRecords.h)
	//exercise57();
}

void exercise52() 
{
	Automobile car1 = Automobile("Chevrolet", "Camaro" , 1969);
	Automobile car2 = Automobile("Ford", "Mustang", 2018);
	cout << car1.fullDescription() << endl;
	cout << car1.automobileAge() << endl;
	cout << car2.fullDescription() << endl;
	cout << car2.automobileAge() << endl;
}

void exercise53() 
{
	VarLenString word1 = VarLenString("Hello");
	VarLenString word2 = VarLenString("World");
	cout << "Words after being constructed: " << endl;
	cout << "Word 1: "; word1.print();
	cout << "Word 2: "; word2.print();
	cout << "Character at function return results: " << endl;
	cout << word1.characterAt(3) << endl;
	cout << "Append function return results: " << endl;
	word2.append('!');
	cout << "Word 2: "; word2.print();
	cout << "Concatenate function return results: " << endl;
	word1.concatenate(word2);
	cout << "Word 1: "; word1.print();
	cout << "Word 2: "; word2.print();
	VarLenString word3(word1);
	VarLenString word4 = VarLenString();
	cout << "Assignment overload function: " << endl;
	word4 = word2;
	cout << "Word 2: "; word2.print();
	cout << "Word 4: "; word4.print();
	cout << "Append function return results: " << endl;
	word4.append('?');
	cout << "Word 2: "; word2.print();
	cout << "Word 4: "; word4.print();
	cout << "Destructor called on Word 1: " << endl;
	word1.~VarLenString();
	cout << "Word 1: "; word1.print();
	cout << "Word 2: "; word2.print();
	cout << "Word 3: "; word3.print();
	cout << "Word 4: "; word4.print();
	cout << "Overloaded function []:" << endl;
	cout << word2[3] << endl;
	cout << word3[0] << endl;
	cout << word3[1] << endl;
	cout << word4[12] << endl;
	cout << word4[2] << endl;
	VarLenString word5 = VarLenString();
	cout << "Remove functions:" << endl;
	word5.remove(2, 2);
	word3.remove(2, 4);
	word4.remove(765, 2);
	word4.remove(0, 0);
	word4.remove(1, 3);
	cout << "Word 3: "; word3.print();
	cout << "Word 4: "; word4.print();
}

void exercise57() 
{
	StudentRecords sr = StudentRecords();
	sr.addRecord(1001, 66);
	sr.addRecord(1032, 87);
	sr.addRecord(1234, 74);
	sr.addRecord(1042, 95);
	sr.addRecord(1203, 54);
	sr.addRecord(1111, 100);
	sr.print();
	cout << sr.averageRecord() << endl;
	cout << endl;
	StudentRecords sr2 = sr.recordsWithinRange(87, 100);
	sr2.print();
}