#include "pch.h"
#include "VarLenString.h"


VarLenString::VarLenString()
{
}

VarLenString::VarLenString(string s)
{
	for (char c : s) 
	{
		this->append(c);
	}
}

VarLenString::VarLenString(const VarLenString & original)
{
	this->listHead = copiedList(original.listHead);
}

VarLenString::~VarLenString()
{
	deleteList(this->listHead);
}

VarLenString & VarLenString::operator=(const VarLenString & rhs)
{
	if (this != &rhs) 
	{
		deleteList(this->listHead);
		this->listHead = copiedList(rhs.listHead);
	}
	return *this;
}

char VarLenString::operator[](int index)
{
	return this->characterAt(index);
}

void VarLenString::print()
{
	charNode * node = this->listHead;
	while (node != NULL)
	{
		cout << node->letter;
		node = node->next;
	}
	cout << endl;
}

void VarLenString::append(char c)
{
	charNode * newNode = new charNode;
	newNode->letter = c;
	newNode->next = NULL;
	if (this->listHead == NULL)
	{
		this->listHead = newNode;
		return;
	}
	charNode * loopPtr = this->listHead;
	while (loopPtr->next != NULL)
	{
		loopPtr = loopPtr->next;
	}
	loopPtr->next = newNode;
}

void VarLenString::concatenate(VarLenString& s2)
{
	charNode * loopPtr = this->listHead;
	while (loopPtr->next != NULL)
	{
		loopPtr = loopPtr->next;
	}
	// create copy a s2
	charNode * currentPtr = s2.listHead;
	charNode * copyPtr = new charNode;
	charList copyS = copyPtr;
	while (currentPtr != NULL)
	{
		copyPtr->letter = currentPtr->letter;
		if (currentPtr->next != NULL)
		{
			copyPtr->next = new charNode;
		}
		else
		{
			copyPtr->next = NULL;
		}
		currentPtr = currentPtr->next;
		copyPtr = copyPtr->next;
	}
	// connect s1 with the copy of s2
	loopPtr->next = copyS;
}

char VarLenString::characterAt(int index)
{
	int count = 1;
	charNode * node = this->listHead;
	while (node != NULL) 
	{
		if (count == index) 
		{
			return node->letter;
		}
		node = node->next;
		count++;
	}
	cout << "Index not found." << endl;
	return NULL;
}

void VarLenString::remove(int start, int len)
{
	int size = 0;
	charNode * loopPtr = this->listHead;
	while (loopPtr != NULL) 
	{
		size++;
		loopPtr = loopPtr->next;
	}
	// if the list is empty, the start is out of range, or len is 0
	// Get out of dodge
	if (size == 0)
	{
		cout << "String is empty." << endl;
		return;
	}
	if (start > size) 
	{
		cout << "Start index is out of range." << endl;
		return;
	}
	if (len <= 0 || start <= 0) 
	{
		cout << "One or more of your parameters was invalid." << endl;
		return;
	}
	int count = 1;
	charNode * current = this->listHead;
	charNode * trailing = NULL;
	while (current != NULL)
	{
		if (count == start || (count > start && len != 0))
		{
			if (trailing == NULL) 
			{
				this->listHead = this->listHead->next;
				current = this->listHead->next;
			}
			else 
			{
				trailing->next = current->next;
				current = trailing->next;
			}
			len--;
		}
		else 
		{
			trailing = current;
			current = current->next;
		}
		count++;
	}
}

void VarLenString::deleteList(charList& listPtr)
{
	while (listPtr != NULL) 
	{
		charNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

VarLenString::charList VarLenString::copiedList(const charList original)
{
	if (original == NULL) 
	{
		return NULL;
	}
	charList newWord = new charNode;
	newWord->letter = original->letter;
	charNode * oldLoopPtr = original->next;
	charNode * newLoopPtr = newWord;
	while (oldLoopPtr != NULL) 
	{
		newLoopPtr->next = new charNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->letter = oldLoopPtr->letter;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newWord;
}
