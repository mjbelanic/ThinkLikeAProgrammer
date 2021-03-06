#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h> 
#include "ConverterClass.h"

using namespace CC;
using namespace std;

void exercise21();
void exercise22();
void exercise23();
void exercise24();
void exercise25();
void exercise26_1();
void exercise26_2();
void exercise27();
char makeChoice(int x);
void exercise29();

int main()
{
	//exercise21();
	//exercise22();
	//exercise23();
	//exercise24();
	//exercise25();
	//exercise26_1();
	//exercise26_2();
	//exercise27();
	//exercise29();
}
void exercise21()
{
	cout << "Exercise 2.1:" << endl;
	for (int row = 1; row <= 4; row++) {
		for (int hashNum = 1; hashNum <= 9 - row; hashNum++) {
			if (hashNum < row) {
				cout << ' ';
			}
			else {
				cout << "#";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void exercise22()
{
	cout << "Exercise 2.2:" << endl;
	for (int row = 4; row >= 1; row--) {
		for (int hashNum = 1; hashNum <= 9 - row; hashNum++) {
			if (hashNum < row) {
				cout << ' ';
			}
			else {
				cout << "#";
			}
		}
		cout << "\n";
	}

	for (int row = 1; row <= 4; row++) {
		for (int hashNum = 1; hashNum <= 9 - row; hashNum++) {
			if (hashNum < row) {
				cout << ' ';
			}
			else {
				cout << "#";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void exercise23()
{
	cout << "Exercise 2.3:" << endl;
	for (int row = 0; row <= 4; row++)
	{
		int preceedingWhiteSpace = row;
		int followingWhiteSpace = 14 - row;
		int middleWhiteSpaces = 14 - 2 * ((row - 1) + row);
		for (int hashNum = 0; hashNum < preceedingWhiteSpace; hashNum++)
		{
			cout << ' ';
		}
		for (int hashNum = 0; hashNum < row; hashNum++)
		{
			cout << '#';
		}
		for (int hashNum = 0; hashNum < middleWhiteSpaces; hashNum++)
		{
			cout << ' ';
		}
		for (int hashNum = 0; hashNum < row; hashNum++)
		{
			cout << '#';
		}
		for (int hashNum = 0; hashNum < followingWhiteSpace; hashNum++)
		{
			cout << ' ';
		}
		cout << "\n";
	}

	for (int row = 4; row >= 0; row--)
	{
		int preceedingWhiteSpace = row;
		int followingWhiteSpace = 14 - row;
		int middleWhiteSpaces = 14 - 2 * ((row - 1) + row);
		for (int hashNum = 0; hashNum < preceedingWhiteSpace; hashNum++)
		{
			cout << ' ';
		}
		for (int hashNum = 0; hashNum < row; hashNum++)
		{
			cout << '#';
		}
		for (int hashNum = 0; hashNum < middleWhiteSpaces; hashNum++)
		{
			cout << ' ';
		}
		for (int hashNum = 0; hashNum < row; hashNum++)
		{
			cout << '#';
		}
		for (int hashNum = 0; hashNum < followingWhiteSpace; hashNum++)
		{
			cout << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
}

void exercise24()
{
	cout << "Exercise 2.4:" << endl;
	int spaceStart = 5;
	int spaceLength = 1;
	for (int row = 0; row <= 5; row++)
	{
		for (int hashNum = 0; hashNum <= 9; hashNum++)
		{
			if (hashNum == spaceStart)
			{
				for (int j = 0; j < spaceLength; j++) {
					cout << '#';
				}
				spaceStart--;
				spaceLength = spaceLength + 2;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}
	for (int row = 0; row <= 10; row++)
	{
		for (int hashNum = 0; hashNum <= 7; hashNum++)
		{
			if (hashNum < 3) {
				cout << ' ';
			}
			else {
				cout << '#';
			}
		}
		cout << '\n';
	}
}

void exercise25()
{
	// Initial Setup of variables
	char digit;
	int checkSum, checker;
	int total = 0;
	int position = 1;
	// Enter number
	cout << "Please enter your 13 digit ISBN code" << endl;
	digit = cin.get();
	while (digit != 10)
	{
		if (position % 2 == 0) { total += (digit - '0') * 3; }
		else { total += digit - '0'; }
		digit = cin.get();
		position++;
	}
	cout << "TOTAL = " << total << endl;
	// Find CheckSum Digit
	checker = total % 10;
	if (checker == 0) { checkSum = 0; }
	else { checkSum = 10 - checker; }

	cout << "CHECKSUM = " << checkSum << endl;
	// Check if ISBN is valid
	total = total + checkSum;
	if (total % 10 == 0) { cout << "ISBN is valid" << endl; }
	else { cout << "ISBN is not valid" << endl; }
}

void exercise26_1()
{
	//Decimal to binary
	cout << "Exercise 2.6.1" << endl;
	cout << "Enter your number:" << endl;
	int position = 1, num, binNum;
	string binString;
	char digit = cin.get();
	while (digit != 10)
	{
		if (position == 1) { num = digit - '0'; }
		else { num = num * 10 + (digit - '0'); }
		digit = cin.get();
		position++;
	}
	while (num > 0)
	{
		binNum = num % 2;
		digit = binNum + '0';
		binString += digit;
		num = num / 2;
	}
	reverse(binString.begin(), binString.end());
	cout << "Your number in Binary is " << binString << endl;
}

void exercise26_2()
{
	// Binary to decimal
	cout << "Exercise 2.6.2" << endl;
	cout << "Enter your number in Binary:" << endl;
	string binString;
	int num = 0, binNum, position = 0;
	char digit = cin.get();
	while (digit != 10)
	{
		binString += digit;
		digit = cin.get();
	}
	for (int i = binString.size() - 1; i >= 0; i--)
	{
		binNum = binString[i] - '0';
		num += binNum * pow(2, position);
		position++;
	}
	cout << "Your number in decimal is: " << num << endl;
}

void exercise27()
{
	cout << "Exercise 27" << endl;
	ConverterClass converter;
	char option1 = makeChoice(1);
	char option2 = makeChoice(2);
	if (option1 == 'B')
	{
		if (option2 == 'B') { converter.B2B(); }
		else if (option2 == 'D') { converter.B2D(); }
		else { converter.B2H(); }
	}
	else if (option1 == 'D')
	{
		if (option2 == 'B') { converter.D2B(); }
		else if (option2 == 'D') { converter.D2D(); }
		else { converter.D2H(); }
	}
	else
	{
		if (option2 == 'B') { converter.H2B(); }
		else if (option2 == 'D') { converter.H2D(); }
		else { converter.H2H(); }
	}
}

char makeChoice(int optionNum)
{
	bool repeat = true;
	char option;
	do {
		if (optionNum == 1)
		{
			cout << "What number base are you starting with? (use number)" << endl;
		}
		else
		{
			cout << "What number base are you changing to? (use number)" << endl;
		}
		cout << "1) Binary" << endl;
		cout << "2) Decimal" << endl;
		cout << "3) Hexidecimal" << endl;
		cin >> option;
		switch (option)
		{
		case '1':
			return 'B';
		case '2':
			return 'D';
		case '3':
			return 'H';
		default:
			cout << "You chose an invalid option" << endl;
			break;
		}
	} while (repeat);
}

void exercise29()
{
	cout << "Exercise 29" << endl;
	cout << "Enter your sentence (Press enter when finished):" << endl;
	string sentence = "", longestWord = "", vowelWord = "", currentWord = "";
	int wordCount = 0, vowelCount = 0, currentVowelNum = 0, charCount = 0;
	char characters;
	characters = cin.get();
	while (characters != 10)
	{
		sentence += characters;
		characters = cin.get();
	}
	char finalChar = sentence[sentence.length() - 1];
	for (char character : sentence)
	{
		// ASCII values for space, . , ! , and ?
		// could be altered to check if char is letter instead
		if (character != 32 && character != 33 && character != 46 && character != 63)
		{
			charCount += 1;
			currentWord += character;
			if (character == 'A' || character == 'E' ||
				character == 'I' || character == 'O' ||
				character == 'U' || character == 'a' ||
				character == 'e' || character == 'i' ||
				character == 'o' || character == 'u')
			{
				currentVowelNum += 1;
			}
		}
		else
		{
			wordCount += 1;
			if (currentWord.length() > longestWord.length())
			{
				longestWord = currentWord;
			}
			if (currentVowelNum > vowelCount)
			{
				vowelWord = currentWord;
				vowelCount = currentVowelNum;
			}
			currentVowelNum = 0;
			currentWord = "";
		}
	}
	if (finalChar != 33 && finalChar != 46 && finalChar != 63)
	{
		wordCount += 1;
		if (currentWord.length() > longestWord.length())
		{
			longestWord = currentWord;
		}
		if (currentVowelNum > vowelCount)
		{
			vowelWord = currentWord;
			vowelCount = currentVowelNum;
		}
	}
	cout << "Your sentence has " << wordCount << " words." << endl;
	cout << "The longest word in your sentence is " << longestWord << "." << endl;
	cout << "The word with the most vowels in your sentence is " << vowelWord << " with " << vowelCount << " vowels." << endl;
}
