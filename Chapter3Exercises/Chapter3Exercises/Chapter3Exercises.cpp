// Chapter3Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h> 

using namespace std;

void exercise31();
int compare_grades(const void * voidA, const void * voidB);
int compare_ids(const void * voidA, const void * voidB);
void exercise32();
int compareFunc(const void * voidA, const void * voidB);
bool exercise33(int aRay[], int length);
void exercise34();
string encryptSentence(string sentence);
void exercise35();
string decryptSentence(string sentence);
void exercise36();
void shuffle(char *arr, size_t n);
void exercise37(int aRay[], int length);
void exercise38();
void exercise39();

struct student {
	int grade;
	int studentID;
	string name;
};

int main()
{
	//exercise31();
	//exercise32();
	//int array1[6] = { 2, 4, 8, 16, 32, 64 };
	//int array2[10] = { 1, 2, 3, 4, 5, 6, 8, 7, 9, 10};
	//cout << exercise33(array1, 6) << endl;
	//cout << exercise33(array2, 10) << endl;
	//exercise34();
	//exercise35();
	//exercise36();
	//int array3[10] = { 2, 3, 2, 1, 6, 3, 2, 6, 4, 9 };
	//int array4[10] = { 10, 22, 3, 4, 15, 6, 8, 37, 29, 10};
	//exercise37(array3, 10);
	//exercise37(array4, 10);
	//exercise38();
	//exercise39();
}

void exercise31() 
{
	const int ARRAY_SIZE = 10;
	student studentArray[ARRAY_SIZE] = {
		{ 87, 10001, "Fred" },
		{ 28, 10002, "Tom" },
		{ 100, 10003, "Alistair" },
		{ 78, 10004, "Sasha" },
		{ 84, 10005, "Erin" },
		{ 98, 10006, "Belinda" },
		{ 75, 10007, "Leslie" },
		{ 70, 10008, "Candy" },
		{ 81, 10009, "Aretha" },
		{ 68, 10010, "Veronica" }
	};
	//use qsort to sort by grade then id
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_grades);
	cout << "Grades" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++) 
	{
		cout << studentArray[i].grade << endl;
	}
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_ids);
	cout << "Student Ids" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << studentArray[i].studentID << endl;
	}
}

int compare_grades(const void *voidA, const void *voidB) 
{
	const student *intA = (student *)(voidA);;
	const student *intB = (student *)(voidB);;
	return intA->grade - intB->grade;
}

int compare_ids(const void * voidA, const void * voidB)
{
	const student *intA = (student *)(voidA);;
	const student *intB = (student *)(voidB);;
	return intA->studentID - intB->studentID;
}

void exercise32() 
{
	//find the sales agent with the highest median
	int total, median, agentNum, highestMedian = 0;
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	int sales[NUM_AGENTS][NUM_MONTHS] = 
	{
		{ 1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32 },
		{ 5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534 },
		{ 23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434 }
	};
	qsort(sales[0], NUM_MONTHS, sizeof(int), compareFunc);
	qsort(sales[1], NUM_MONTHS, sizeof(int), compareFunc);
	qsort(sales[2], NUM_MONTHS, sizeof(int), compareFunc);
	int middlePoint = NUM_MONTHS / 2;
	if (NUM_MONTHS % 2 == 0) 
	{
		for (int i = 0; i < NUM_AGENTS; i++) {
			total = sales[i][middlePoint] + sales[i][middlePoint - 1];
			median = total / 2;
			if (median >= highestMedian) 
			{
				highestMedian = median;
				agentNum = i;
			}
		}
	}
	else 
	{
		for (int i = 0; i < NUM_AGENTS; i++) 
		{
			median = sales[i][middlePoint];
			if (median >= highestMedian)
			{
				highestMedian = median;
				agentNum = i;
			}
		}
	}
	cout << "The agent with the highest sales median is agent " << agentNum + 1 << " with a median sales of " << highestMedian << endl;
}

int compareFunc(const void * voidA, const void * voidB) 
{
	int *intA = (int *)(voidA);
	int *intB = (int *)(voidB);
	return *intA - *intB;
}

bool exercise33(int aRay[], int length) 
{
	for (int i = 1; i < length; i++) 
	{
		if (aRay[i] < aRay[i - 1]) 
		{
			return false;
		}
	}
	return true;
}

void exercise34() 
{
	cout << "Please enter your sentence:" << endl;
	string sentence = "";
	char c = cin.get();
	while (c != 10) 
	{
		sentence += c;
		c = cin.get();
	}
	string encryptedSentence = encryptSentence(sentence);
	cout << encryptedSentence << endl;
}

string encryptSentence(string sentence) 
{
	int i;
	string newSentence = "";
	char cipher[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V',
	'B', 'N', 'M' };
	for (char c : sentence) 
	{
		if (c >= 'A' && c <= 'Z') 
		{
			i = c - 'A';
			newSentence += cipher[i];
		}
		else if (c >= 'a' && c <= 'z') 
		{
			i = c - 'a';
			newSentence += cipher[i];
		}
		else 
		{
			newSentence += c;
		}
	}
	return newSentence;
}

void exercise35() 
{
	cout << "Please enter your message:" << endl;
	string sentence = "";
	char c = cin.get();
	while (c != 10)
	{
		if (c >= 'a' && c <= 'z') 
		{
			cout << "Message must be in all caps. (Minus punctuation)" << endl;
			return;
		}
		else
		{
			sentence += c;
			c = cin.get();
		}
	}
	string decryptedSentence = decryptSentence(sentence);
	cout << decryptedSentence << endl;
}

string decryptSentence(string sentence) 
{
	int i;
	string newSentence = "";
	char cipher[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V',
	'B', 'N', 'M' };
	char codeCracker[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z' };
	for (char c : sentence)
	{
		if (c >= 'A' && c <= 'Z')
		{
			for (i = 0; i < 26; i++) 
			{
				if (c == cipher[i]) {
					newSentence += codeCracker[i];
				}
			}
		}
		else
		{
			newSentence += c;
		}
	}
	return newSentence;
}

void exercise36() 
{
	char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z' };
	char cipher[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
	'X', 'Y', 'Z' };
	bool shuffled = false;
	do {
		shuffle(cipher, 26);
		int matches = 0;
		for (int i = 0; i < 26; i++) 
		{
			if (alphabet[i] != cipher[i]) 
			{
				continue;
			}
			else 
			{
				matches += 1;
			}
		}
		if (matches == 0) 
		{
			shuffled = true;
		}
	} while (shuffled != true);
	int i;
	string sentence = "", newSentence;
	cout << "Please enter your sentence." << endl;
	char c = cin.get();
	while (c != 10)
	{
		sentence += c;
		c = cin.get();
	}
	for (char c : sentence)
	{
		if (c >= 'A' && c <= 'Z')
		{
			i = c - 'A';
			newSentence += cipher[i];
		}
		else if (c >= 'a' && c <= 'z')
		{
			i = c - 'a';
			newSentence += cipher[i];
		}
		else
		{
			newSentence += c;
		}
	}
	cout << newSentence << endl;
}

// Shuffle function taken from https://stackoverflow.com/questions/20734774/random-array-generation-with-no-duplicates 
void shuffle(char *arr, size_t n)
{
	if (n > 1)
	{
		size_t i;
		srand(time(NULL));
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
		}
	}
}

void exercise37(int aRay[], int length)
{
	int masterCount = 0, currentCount = 0;
	qsort(aRay, length, sizeof(int), compareFunc);
	int mode = aRay[0], currentNum = aRay[0];
	for (int i = 0; i < length; i++) 
	{
		if (currentNum != aRay[i]) 
		{
			if (currentCount > masterCount) 
			{
				masterCount = currentCount;
				mode = currentNum;
				currentCount = 1;
				currentNum = aRay[i];
			}
			else 
			{
				currentCount = 1;
				currentNum = aRay[i];
			}
		}
		else 
		{
			currentCount += 1;
		}
	}
	cout << "The mode of the array is " << mode << endl;
	cout << "It appears " << masterCount << " times" << endl;
}

void exercise38() 
{
	const int ARRAY_SIZE = 10;
	int total, halfMedian, quarterMedian, threeQuarterMedian;
	student studentArray[ARRAY_SIZE] = {
		{ 87, 10001, "Fred" }, { 28, 10002, "Tom" },
		{ 100, 10003, "Alistair" },	{ 78, 10004, "Sasha" },
		{ 84, 10005, "Erin" }, { 98, 10006, "Belinda" },
		{ 75, 10007, "Leslie" }, { 70, 10008, "Candy" },
		{ 81, 10009, "Aretha" }, { 68, 10010, "Veronica" }
	};
	qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_grades);
	int middlePoint = ARRAY_SIZE / 2;
	int quarterPoint = middlePoint / 2;
	int threeFourthsPoint = middlePoint + quarterPoint;
	if (ARRAY_SIZE % 2 == 0)
	{
		total = studentArray[middlePoint].grade + studentArray[middlePoint - 1].grade;
		halfMedian = total / 2;
		quarterMedian = studentArray[quarterPoint].grade;
		threeQuarterMedian = studentArray[threeFourthsPoint].grade;
	}
	else 
	{
		halfMedian = studentArray[middlePoint].grade;
		total = studentArray[quarterPoint].grade + studentArray[quarterPoint + 1].grade;
		quarterMedian = total / 2;
		total = studentArray[threeFourthsPoint].grade + studentArray[threeFourthsPoint + 1].grade;
		threeQuarterMedian = total / 2;
	}
	cout << "To do better than 25%: " << quarterMedian << endl;
	cout << "To do better than 50%: " << halfMedian << endl;
	cout << "To do better than 75%: " << threeQuarterMedian << endl;
}

void exercise39() 
{
	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;
	vector<int> saleMonthData;
	int sum, median, agentNum, highestMedian = 0;
	int sales[NUM_AGENTS][NUM_MONTHS] =
	{
		{ -1, -1, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32 },
		{ 5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, -1, -1, -1 },
		{ -1, -1, 67, 99, 265, 376, 232, 223, 4546, 564, -1, -1 }
	};
	for (int i = 0; i < NUM_AGENTS; i++) 
	{
		int total = 0;
		int monthsActive = 0;
		for (int j = 0; j < NUM_MONTHS; j++) 
		{
			if (sales[i][j] != -1) 
			{
				total += sales[i][j];
				monthsActive += 1;
				saleMonthData.push_back(sales[i][j]);
			}
		}
		sort(saleMonthData.begin(), saleMonthData.end());
		int middlePoint = monthsActive / 2;

		if (monthsActive % 2 == 0) {
			sum = saleMonthData.at(middlePoint) + saleMonthData.at(middlePoint - 1);
			median = sum / 2;
		}
		else 
		{
			median = saleMonthData.at(middlePoint);
		}
		if (median >= highestMedian)
		{
			highestMedian = median;
			agentNum = i + 1;
		}
		cout << "Agent " << i + 1 << " was active " << monthsActive << " months." << endl;
		cout << "Agent " << i + 1 << " average sales was " << total / monthsActive << "." << endl;
		cout << "Agent " << i + 1 << " median sales was " << median << "." << endl;
	}
	cout << "Agent " << agentNum << " had the highest median sales." << endl;
}