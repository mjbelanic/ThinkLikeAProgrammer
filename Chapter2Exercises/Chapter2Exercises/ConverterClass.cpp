#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h> 
#include "ConverterClass.h";

using namespace CC;
using namespace std;

void ConverterClass::D2D()
{
	cout << "Enter your number:" << endl;
	int position = 1, num, binNum;
	string binString;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	while (digit != 10)
	{
		if (position == 1) { num = digit - '0'; }
		else { num = num * 10 + (digit - '0'); }
		digit = cin.get();
		position++;
	}
	cout << num << endl;
}

void ConverterClass::B2D()
{
	cout << "Enter your number:" << endl;
	string binString;
	int num = 0, binNum, position = 0;
	cin.clear();
	cin.ignore();
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
	cout << num << endl;
}

void ConverterClass::H2D()
{
	cout << "Enter your number:" << endl;
	string hexString;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	int num = 0, hexNum, position = 0;
	while (digit != 10)
	{
		hexString += digit;
		digit = cin.get();
	}
	for (int i = hexString.length() - 1; i >= 0; i--)
	{
		if (hexString[i] >= '0' && hexString[i] <= '9')
		{
			hexNum = hexString[i] - '0';
			num += hexNum * pow(16, position);
			position++;
		}
		else if (hexString[i] >= 'A' && hexString[i] <= 'F')
		{
			hexNum = hexString[i] - 55;
			num += hexNum * pow(16, position);
			position++;
		}
		else if (hexString[i] >= 'a' && hexString[i] <= 'f')
		{
			hexNum = hexString[i] - 87;
			num += hexNum * pow(16, position);
			position++;
		}
		else
		{
			cout << "You entered an invalid number";
			return;
		}
	}
	cout << num << endl;
}

void ConverterClass::B2B()
{
	cout << "Enter your number:" << endl;
	string binString;
	int num = 0, binNum, position = 0;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	while (digit != 10)
	{
		binString += digit;
		digit = cin.get();
	}
	cout << binString << endl;
}

void ConverterClass::D2B()
{
	cout << "Enter your number:" << endl;
	int position = 1, num, binNum;
	string binString;
	cin.clear();
	cin.ignore();
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
	cout << binString << endl;
}

void ConverterClass::H2B()
{
	cout << "Enter your number:" << endl;
	int num, binNum;
	string hexString, binString;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	while (digit != 10)
	{
		hexString += digit;
		digit = cin.get();
	}
	for (char digit : hexString)
	{
		string sb = "";
		if (digit >= '0' && digit <= '9')
		{
			num = digit - '0';
			while (num > 0)
			{
				binNum = num % 2;
				digit = binNum + '0';
				sb += digit;
				num = num / 2;
			}
			if (sb.length() < 4)
			{
				while (sb.length() < 4)
				{
					sb += '0';
				}
			}
			reverse(sb.begin(), sb.end());
			binString += sb;
		}
		else
		{
			if (digit >= 'A' && digit <= 'F')
			{
				num = digit - 55;
				while (num > 0)
				{
					binNum = num % 2;
					digit = binNum + '0';
					sb += digit;
					num = num / 2;
				}
				if (sb.length() < 4)
				{
					while (sb.length() < 4)
					{
						sb += '0';
					}
				}
				reverse(sb.begin(), sb.end());
				binString += sb;
			}
			else if (digit >= 'a' && digit <= 'f')
			{
				num = digit - 87;
				while (num > 0)
				{
					binNum = num % 2;
					digit = binNum + '0';
					sb += digit;
					num = num / 2;
				}
				if (sb.length() < 4)
				{
					while (sb.length() < 4)
					{
						sb += '0';
					}
				}
				reverse(sb.begin(), sb.end());
				binString += sb;
			}
			else
			{
				cout << "You entered an invalid number";
				return;
			}
		}
	}
	cout << binString << endl;
}

void ConverterClass::H2H()
{
	cout << "Enter your number:" << endl;
	string hexString;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	while (digit != 10)
	{
		hexString += digit;
		digit = cin.get();
	}
	cout << hexString << endl;
}

void ConverterClass::D2H()
{
	cout << "Enter your number:" << endl;
	int position = 1, num, hexNum;
	string hexString;
	cin.clear();
	cin.ignore();
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
		hexNum = num % 16;
		if (hexNum <= 9) { digit = hexNum + '0'; }
		else { digit = hexNum + '7'; }
		hexString += digit;
		num = num / 16;
	}
	reverse(hexString.begin(), hexString.end());
	cout << hexString << endl;
}

void ConverterClass::B2H()
{
	cout << "Enter your number:" << endl;
	string binString, hexString, sb;
	int num = 0, binNum, position = 0;
	cin.clear();
	cin.ignore();
	char digit = cin.get();
	while (digit != 10)
	{
		binString += digit;
		digit = cin.get();
	}
	if (binString.length() % 4 != 0)
	{
		reverse(binString.begin(), binString.end());
		while (binString.length() % 4 != 0)
		{
			binString += '0';
		}
		reverse(binString.begin(), binString.end());
	}
	for (int i = 0; i <= binString.length(); i++)
	{
		sb += binString[i];
		if (sb.length() % 4 == 0)
		{
			for (int j = sb.length() - 1; j >= 0; j--)
			{
				binNum = sb[j] - '0';
				num += binNum * pow(2, position);
				position++;
			}
			if (num <= 9) { digit = num + '0'; }
			else { digit = num + '7'; }
			hexString += digit;
			sb = "";
			num = 0;
			position = 0;
		}
	}
	cout << hexString << endl;
}