#pragma once
#include <string>
#include <iostream>
using namespace std;

class VarLenString
{
private:
	struct charNode
	{
		char letter;
		charNode * next;
	};
public:
	VarLenString();
	VarLenString(string s);
	VarLenString(const VarLenString &original);
	~VarLenString();
	VarLenString& operator=(const VarLenString& rhs);
	char operator[](int index);
	void print();
	void append(char c);
	void concatenate(VarLenString& s2);
	char characterAt(int index);
	void remove(int start, int len);
private:
	typedef charNode * charList;
	charList listHead;
	void deleteList(charList &listPtr);
	charList copiedList(const charList original);
};

