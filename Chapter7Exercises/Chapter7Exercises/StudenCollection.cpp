#include "pch.h"
#include "StudenCollection.h"

StudentCollection::StudentCollection()
{
	this->listHead = NULL;
	this->currentPolicy = NULL;
}

StudentCollection::~StudentCollection()
{
	deleteList(this->listHead);
}

StudentCollection & StudentCollection::operator=(const StudentCollection & rhs)
{
	if (this != &rhs)
	{
		deleteList(this->listHead);
		this->listHead = copiedList(rhs.listHead);
	}
	return *this;
}

void StudentCollection::setFirstStudentPolicy(firstStudentPolicy f)
{
	this->currentPolicy = f;
}

void StudentCollection::print()
{
	int count = 1;
	studentNode * node = this->listHead;
	while (node != NULL)
	{
		cout << "Student #" << count << ":" << endl;
		cout << "Student Number: " << node->studentData.studentId << endl;
		cout << "Student Grade: " << node->studentData.grade << endl;
		count++;
		node = node->next;
	}
}

void StudentCollection::addRecord(studentRecord newStudent)
{
	if (IsValidGradeValue(newStudent.grade))
	{
		cout << "Invalid grade entered." << endl;
		return;
	}
	studentNode * node = new studentNode;
	node->studentData = newStudent;
	node->next = this->listHead;
	this->listHead = node;
}

void StudentCollection::deleteList(studentList & listPtr)
{
	while (listPtr != NULL)
	{
		studentNode * temp = listPtr;
		listPtr = listPtr->next;
		delete temp;
	}
}

StudentCollection::studentList StudentCollection::copiedList(const studentList original)
{
	if (original == NULL)
	{
		return NULL;
	}
	studentList newList = new studentNode;
	newList->studentData = original->studentData;
	studentNode * oldLoopPtr = original->next;
	studentNode * newLoopPtr = newList;
	while (oldLoopPtr != NULL)
	{
		newLoopPtr = new studentNode;
		newLoopPtr = newLoopPtr->next;
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newList;
}

bool StudentCollection::IsValidGradeValue(int grade)
{
	return (grade < 0 || grade > 100);
}

void StudentCollection::choosePolicy(policy p)
{
	if (p == policy::higherGrade)
	{
		this->currentPolicy = &StudentCollection::higherGrade;
	}
	else if (p == policy::lowerStudentNumber)
	{
		this->currentPolicy = &StudentCollection::lowerStudentNumber;
	}
	else if (p == policy::nameComesFirst)
	{
		this->currentPolicy = &StudentCollection::nameComesFirst;
	}
}

studentRecord StudentCollection::firstStudent()
{
	if (this->listHead == NULL || this->currentPolicy == NULL) 
	{
		studentRecord dummyRecord{ -1,-1,"" };
		return dummyRecord;
	}
	studentNode * loopPtr = this->listHead;
	studentRecord first = loopPtr->studentData;
	loopPtr = loopPtr->next;
	while (loopPtr != NULL) 
	{
		if ((this->*currentPolicy)(loopPtr->studentData, first)) 
		{
			first = loopPtr->studentData;
		}
		loopPtr = loopPtr->next;
	}
	return first;
}