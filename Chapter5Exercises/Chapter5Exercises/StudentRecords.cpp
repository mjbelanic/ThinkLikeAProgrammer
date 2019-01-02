#include "pch.h"
#include "StudentRecords.h"


StudentRecords::StudentRecords()
{
}

StudentRecords::~StudentRecords()
{
	deleteList(this->listHead);
}

StudentRecords & StudentRecords::operator=(const StudentRecords & rhs)
{
	if (this != &rhs) 
	{
		deleteList(this->listHead);
		this->listHead = copiedList(rhs.listHead);
	}
	return *this;
}

StudentRecords& StudentRecords::recordsWithinRange(int lowGrade, int highGrade)
{
	listNode * loopPtr = this->listHead;
	StudentRecords * newRecords = new StudentRecords;
	studentList list = new listNode;
	if (IsValidGradeValue(lowGrade) && IsValidGradeValue(highGrade))
	{
		cout << "One or both grade values entered are invalid." << endl;
		return *newRecords;
	}
	while (loopPtr != NULL) 
	{
		if (loopPtr->grade >= lowGrade && loopPtr->grade <= highGrade) 
		{
			listNode * node = new listNode;
			node->studentNum = loopPtr->studentNum;
			node->grade = loopPtr->grade;
			node->next = newRecords->listHead;
			newRecords->listHead = node;
		}
		loopPtr = loopPtr->next;
	}
	return *newRecords;
}

void StudentRecords::print()
{
	int count = 1;
	listNode * node = this->listHead;
	while (node != NULL) 
	{
		cout << "Student #" << count << ":" << endl;
		cout << "Student Number: " << node->studentNum << endl;
		cout << "Student Grade: " << node->grade << endl;
		count++;
		node = node->next;
	}
}

void StudentRecords::addRecord(int studentNum, int grade)
{
	if (IsValidGradeValue(grade)) 
	{
		cout << "Invalid grade entered." << endl;
		return;
	}
	listNode * node = new listNode;
	node->studentNum = studentNum;
	node->grade = grade;
	node->next = this->listHead;
	this->listHead = node;
}

double StudentRecords::averageRecord()
{
	listNode * node = this->listHead;
	double count = 0.0;
	double totalScore = 0.0;
	if (node == NULL)
	{
		cout << "There are no records present" << endl;
		return 0.0;
	}
	while (node != NULL)
	{
		totalScore += node->grade;
		count++;
		node = node->next;
	}
	double averageScore = totalScore / count;
	return averageScore;
}

void StudentRecords::deleteList(studentList & listPtr)
{
	while (listPtr != NULL)
	{
		listNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

StudentRecords::studentList StudentRecords::copiedList(const studentList original)
{
	if (original == NULL) 
	{
		return NULL;
	}
	studentList newList = new listNode;
	newList->studentNum = original->studentNum;
	newList->grade = original->grade;
	listNode * oldLoopPtr = original->next;
	listNode * newLoopPtr = newList;
	while (oldLoopPtr != NULL) 
	{
		newLoopPtr = new listNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentNum = oldLoopPtr->studentNum;
		newLoopPtr->grade = oldLoopPtr->grade;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newList;
}

bool StudentRecords::IsValidGradeValue(int grade) 
{
	return (grade < 0 || grade > 100);
}
