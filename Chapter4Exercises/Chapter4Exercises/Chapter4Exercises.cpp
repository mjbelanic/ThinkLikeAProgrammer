#include "pch.h"
#include <iostream>

using namespace std;

typedef char * stringArray;
struct listNode 
{
	int studentNum;
	int grade;
	listNode * next;
};
typedef listNode * studentCollection;
struct charNode 
{
	char character;
	charNode * next;
};
typedef charNode * charCollection;
struct numNode 
{
	int num;
	numNode * next;
};
typedef numNode * numCollection;

void output(stringArray& baseString);
void printList(charCollection& charList);
void printList(numCollection& numList);
int getLen(stringArray baseString);
void concatenate(stringArray& s1, stringArray s2);
void append(stringArray& baseString, char c);
void alternativeAppend(stringArray& baseString, char c);
void alternativeConcatenate(stringArray& s1, stringArray s2);
char alternativeCharacterAt(stringArray& s1, int index);
void exercise41();
void reverse(stringArray& aRay);
void exercise42();
stringArray findSubstring(stringArray& baseString, int startPos, int length);
void exercise43();
void replaceString(stringArray& source, stringArray target, stringArray replaceText);
bool compareStringArrays(stringArray& substring, stringArray& target);
void exercise44();
void exercise45();
void removeRecord(studentCollection& sc, int studentId);
void exercise46();
char listCharacterAt(charCollection& charList, int position);
void listAppend(charCollection& charList, char c);
void exercise47();
void listConcatenate(charCollection& s1, charCollection s2);
void exercise48();
void removeChars(charCollection& s1, int startPos, int length);
void setNodeValues(charNode* currentNode, charNode* copyNode);
void exercise49();
numCollection intToList(int num);
void addRecord(numCollection& numList, int digit);
void exercise410();
int numListToInt(numCollection numList);

int main()
{
	//exercise41();
	//exercise42();
	//exercise43();
	//exercise44();
	//exercise45();
	//exercise46();
	//exercise47();
	//exercise48();
	//exercise49();
	//exercise410();
}

void output(stringArray& baseString)
{
	if ((baseString[0] > 'A' && baseString[0] < 'Z') || (baseString[0] >= 'a' && baseString[0] <= 'z'))
	{
		int i = 0;
		while (baseString[i] != 0)
		{
			cout << baseString[i];
			i++;
		}
	}
	else 
	{
		int i = 1;
		while (i < baseString[0])
		{
			cout << baseString[i];
			i++;
		}
	}
}

void printList(charCollection& charList) 
{
	charNode * node = charList;
	while (node != NULL)
	{
		cout << node->character;
		node = node->next;
	}
	cout << endl;
}

void printList(numCollection& numList)
{
	numNode * node = numList;
	while (node != NULL)
	{
		cout << node->num;
		node = node->next;
	}
	cout << endl;
}

int getLen(stringArray baseString)
{
	int count = 0;
	while (baseString[count] != 0)
	{
		count++;
	}
	return count;
}

void concatenate(stringArray& s1, stringArray s2) 
{
	int s1_OldLen = getLen(s1);
	int s2_Len = getLen(s2);
	int s1_NewLen = s1_OldLen + s2_Len;
	stringArray newString = new char[s1_NewLen + 1];
	for (int i = 0; i < s1_OldLen; i++) 
	{
		newString[i] = s1[i];
	}
	for (int i = 0; i < s2_Len; i++) 
	{
		newString[s1_OldLen + i] = s2[i];
	}
	newString[s1_NewLen] = 0;
	delete[] s1;
	s1 = newString;
}

void append(stringArray& baseString, char c) 
{
	int oldLen = getLen(baseString);
	stringArray newString = new char[oldLen + 2];
	for (int i = 0; i < oldLen; i++) 
	{
		newString[i] = baseString[i];
	}
	newString[oldLen] = c;
	newString[oldLen + 1] = 0;
	delete[] baseString;
	baseString = newString;
}

void exercise41() 
{
	stringArray word = new char[8];
	word[0] = 't'; word[1] = 'e'; word[2] = 's'; word[3] = 't'; word[4] = 'i';
	word[5] = 'n'; word[6] = 'g'; word[7] = 0;
	reverse(word);
	for (int i = 0; i < 8; i++)
	{
		cout << word[i];
	}
}

void reverse(stringArray& aRay)
{
	stringArray newAray = new char[8];
	int newPos = 6;
	for (int i = 0; i < 7; i++) 
	{
		newAray[newPos] = aRay[i];
		newPos--;
	}
	newAray[7] = 0;
	delete[] aRay;
	aRay = newAray;
}

void exercise42() 
{
	stringArray word = new char[8];
	word[0] = 't'; word[1] = 'e'; word[2] = 's'; word[3] = 't'; word[4] = 'i';
	word[5] = 'n'; word[6] = 'g'; word[7] = 0;
	stringArray subString = findSubstring(word, 3, 8);
	output(subString);
}

stringArray findSubstring(stringArray& baseString, int startPos, int length) 
{
	if (length > getLen(baseString))
	{
		length = getLen(baseString);
	}
	stringArray subString = new char[length + 1];
	for (int i = 0; i < length; i++) 
	{
		subString[i] = baseString[i + (startPos-1)];
	}
	subString[length] = 0;
	return subString;
}

void exercise43() 
{
	stringArray word = new char[8];
	stringArray target = new char[5];
	stringArray replaceText = new char[4];
	word[0] = 't'; word[1] = 'e'; word[2] = 's'; word[3] = 't'; word[4] = 'i';
	word[5] = 'n'; word[6] = 'g'; word[7] = 0;
	target[0] = 't'; target[1] = 'i'; target[2] = 'n'; target[3] = 'g'; target[4] = 0;
	replaceText[0] = 'c'; replaceText[1] = 'o'; replaceText[2] = 'd'; replaceText[3] = 0;
	replaceString(word, target, replaceText);
	output(word);
}

void replaceString(stringArray& source, stringArray target, stringArray replaceText) 
{
	// get all necessary lengths of each stringArray
	int targetLen = getLen(target), sourceLen = getLen(source), replaceLen = getLen(replaceText);
	stringArray newString = new char[1];
	newString[0] = 0;
	for (int i = 0; i < sourceLen; i++)
	{
		// needs the additional 1 because it starts index at 1;
		stringArray substring = findSubstring(source, i+1, targetLen);
		bool sameString = compareStringArrays(substring, target);
		if (sameString) 
		{
			concatenate(newString, replaceText);
			i += (targetLen - 1);
		}
		else 
		{
			append(newString, source[i]);
		}
		delete[] substring;
	}
	delete[] source;
	source = newString;
}

bool compareStringArrays(stringArray& substring, stringArray& target) 
{
	bool sameString = true;
	for (int i = 0; i < getLen(substring); i++) 
	{
		if (substring[i] != target[i]) 
		{
			sameString = false;
		}
	}
	return sameString;
}

void exercise44() 
{
	stringArray word = new char[6];
	word[0] = 6; word[1] = 'H'; word[2] = 'e'; word[3] = 'l'; word[4] = 'l';
	word[5] = 'o';
	stringArray secondWord = new char[6];
	secondWord[0] = 6; secondWord[1] = 'W'; secondWord[2] = 'o'; secondWord[3] = 'r';
	secondWord[4] = 'l'; secondWord[5] = 'd';
	alternativeConcatenate(word, secondWord);
	char c = alternativeCharacterAt(word, 9);
	cout << c << endl;
	alternativeAppend(word, '!');
	output(word);
}

void alternativeAppend(stringArray& baseString, char c) 
{
	int oldLen = baseString[0];
	int newLen = oldLen + 1;
	stringArray newString = new char[newLen];
	for (int i = 1; i < oldLen; i++)
	{
		newString[i] = baseString[i];
	}
	newString[oldLen] = c;
	newString[0] = newLen;
	delete[] baseString;
	baseString = newString;
}

void alternativeConcatenate(stringArray& baseString, stringArray s2)
{
	int baseString_OldLen = baseString[0];
	int s2_Len = s2[0] - 1;
	int baseString_NewLen = baseString_OldLen + s2_Len;
	stringArray newString = new char[baseString_NewLen];
	for (int i = 1; i < baseString_OldLen; i++)
	{
		newString[i] = baseString[i];
	}
	for (int i = 0; i < s2_Len; i++)
	{
		newString[baseString_OldLen + i] = s2[i+1];
	}
	newString[0] = baseString_NewLen;
	delete[] baseString;
	baseString = newString;
}

char alternativeCharacterAt(stringArray& baseString, int index)
{
	if (index == 0) 
	{
		cout << "Not a valid index." << endl;
		return NULL;
	}
	else if(index > baseString[0])
	{
		cout << "Not a valid index." << endl;
		return NULL;
	}
	else 
	{
		return baseString[index];
	}
}

void exercise45() 
{
	studentCollection sc;
	listNode * node1 = new listNode;
	node1->studentNum = 1001; node1->grade = 78;
	listNode * node2 = new listNode;
	node2->studentNum = 1012; node2->grade = 93;
	listNode * node3 = new listNode;
	node3->studentNum = 1076; node3->grade = 85;
	listNode * node4 = new listNode;
	node4->studentNum = 1111; node4->grade = 99;
	sc = node1;
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = NULL;
	node1 = node2 = node3 = node4 = NULL;
	removeRecord(sc, 1076);
	listNode * node = sc;
	while (node != NULL) 
	{
		cout << node->studentNum << endl;
		node = node->next;
	}
}

void removeRecord(studentCollection& sc, int studentId) 
{
	if (sc == NULL) 
	{
		return;
	}
	listNode * loopPtr = sc;
	listNode * prevPtr = NULL;
	while (loopPtr != NULL)
	{
		if (loopPtr->studentNum == studentId) 
		{
			if (prevPtr == NULL) 
			{
				sc = loopPtr->next;
			}
			else 
			{
				prevPtr->next = loopPtr->next;
			}
		}
		prevPtr = loopPtr;
		loopPtr = loopPtr->next;
	}
}

void exercise46() 
{
	charCollection word;
	charCollection word2;
	charNode * node1 = new charNode; node1->character = 't';
	charNode * node2 = new charNode; node2->character = 'e';
	charNode * node3 = new charNode; node3->character = 's';
	charNode * node4 = new charNode; node4->character = 't';
	charNode * node5 = new charNode; node5->character = NULL;
	word = node1; word2 = node5;
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = NULL;
	node1 = node2 = node3 = node4 = node5 = NULL;
	listAppend(word, '!');
	printList(word);
	listAppend(word2, '!');
	printList(word2);
	char c = listCharacterAt(word, 3);
	cout << c << endl;
}

void listAppend(charCollection& charList, char c) 
{
	if (charList->character == NULL)
	{
		charList->character = c;
		charList->next = NULL;
		return;
	}
	charNode * loopPtr = charList;
	charNode * newNode = new charNode;
	newNode->character = c;
	newNode->next = NULL;
	while (loopPtr->next != NULL)
	{
		loopPtr = loopPtr->next;
	}
	loopPtr->next = newNode;
}

char listCharacterAt(charCollection& charList, int position)
{
	int count = 1;
	charNode * node = charList;
	while (node != NULL) 
	{
		if (count == position) 
		{
			return node->character;
		}
		node = node->next;
		count++;
	}
	cout << "String does not have an value at position: " << position << endl;
	return NULL;
}

void exercise47() 
{
	charCollection word;
	charCollection word2;
	charNode * node1 = new charNode; node1->character = 'H'; charNode * node2 = new charNode; node2->character = 'e';
	charNode * node3 = new charNode; node3->character = 'l'; charNode * node4 = new charNode; node4->character = 'l';
	charNode * node5 = new charNode; node5->character = 'o'; charNode * node6 = new charNode; node6->character = 'W';
	charNode * node7 = new charNode; node7->character = 'o'; charNode * node8 = new charNode; node8->character = 'r';
	charNode * node9 = new charNode; node9->character = 'l'; charNode * node10 = new charNode; node10->character = 'd';
	word = node1; node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5; node5->next = NULL;
	node1 = node2 = node3 = node4 = node5 = NULL;
	word2 = node6; node6->next = node7; node7->next = node8; node8->next = node9; node9->next = node10; node10->next = NULL;
	node6 = node7 = node8 = node9 = node10 = NULL;
	listConcatenate(word, word2);
	printList(word);
}

void listConcatenate(charCollection& s1, charCollection s2)
{
	charNode * loopPtr = s1;
	while (loopPtr->next != NULL)
	{
		loopPtr = loopPtr->next;
	}
	// create copy a s2
	charNode * currentPtr = s2;
	charNode * copyPtr = new charNode;
	charCollection copyS = copyPtr;
	while (currentPtr != NULL) 
	{
		setNodeValues(currentPtr, copyPtr);
		currentPtr = currentPtr->next;
		copyPtr = copyPtr->next;
	}
	// connect s1 with the copy of s2
	loopPtr->next = copyS;
}

void exercise48() 
{
	charCollection word;
	charNode * node1 = new charNode; node1->character = 't'; charNode * node2 = new charNode; node2->character = 'e';
	charNode * node3 = new charNode; node3->character = 's'; charNode * node4 = new charNode; node4->character = 't';
	charNode * node5 = new charNode; node5->character = 'i'; charNode * node6 = new charNode; node6->character = 'n';
	charNode * node7 = new charNode; node7->character = 'g';
	word = node1; node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5; node5->next = node6;
	node6->next = node7; node7->next = NULL;
	node1 = node2 = node3 = node4 = node5 = node6 = node7 = NULL;
	removeChars(word, 2, 4);
	printList(word);
}

void removeChars(charCollection& s1, int startPos, int length)
{
	charNode * currentPtr = s1;
	charNode * copyPtr = new charNode;
	charCollection newWord = copyPtr;
	int count = 0; 
	while (currentPtr != NULL)
	{
		count++;
		if (count < startPos || length == 0)
		{
			setNodeValues(currentPtr, copyPtr);
			copyPtr = copyPtr->next;
		}
		else if(count == startPos && length != 0)
		{
			copyPtr->character = NULL;
			copyPtr->next = NULL;
			length--;
		}
		else if (count > startPos && length != 0) 
		{
			length--;
		}
		currentPtr = currentPtr->next;
	}
	delete[] s1;
	s1 = newWord;
}

void setNodeValues(charNode* currentNode, charNode* copyNode)
{
	copyNode->character = currentNode->character;
	if (currentNode->next != NULL)
	{
		copyNode->next = new charNode;
	}
	else
	{
		copyNode->next = NULL;
	}
}

void exercise49() 
{
	int num = 925746;
	numCollection numList = intToList(num);
	printList(numList);
}

numCollection intToList(int num)
{
	int digit;
	numCollection numList = NULL;
	while (num > 0)
	{
		digit = num % 10;
		num = num / 10;
		addRecord(numList, digit);
	}
	return numList;
}

void addRecord(numCollection& numList, int digit) 
{
	numNode * newNode = new numNode;
	newNode->num = digit;
	newNode->next = numList;
	numList = newNode;
}

void exercise410() 
{
	numCollection numList1;
	numCollection numList2;
	numNode * node1 = new numNode; node1->num = 6; numNode * node2 = new numNode; node2->num = 2;
	numNode * node3 = new numNode; node3->num = 0; numNode * node4 = new numNode; node4->num = 7;
	numNode * node5 = new numNode; node5->num = 3; numNode * node6 = new numNode; node6->num = 9;
	numList1 = node1; node1->next = node2; node2->next = node3; node3->next = NULL; 
	numList2 = node4; node4->next = node5; node5->next = node6; node6->next = NULL;
	int num1 = numListToInt(numList1); 
	int num2 = numListToInt(numList2);
	int total = num1 + num2;
	numCollection numListTotal = intToList(total);
	printList(numListTotal);
}

int numListToInt(numCollection numList) 
{
	int total = 0;
	numNode * node = numList;
	while (node != NULL)
	{
		total += node->num;
		if (node->next != NULL) {
			total *= 10;
		}
		node = node->next;
	}
	return total;
}