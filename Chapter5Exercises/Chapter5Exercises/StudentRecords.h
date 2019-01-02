#pragma once
#include <string>
#include <iostream>
using namespace std;

class StudentRecords
{
private:
	struct listNode
	{
		int studentNum;
		int grade;
		listNode * next;
	};
public:
	StudentRecords();
	~StudentRecords();
	StudentRecords& operator=(const StudentRecords& rhs);
	StudentRecords& recordsWithinRange(int lowGrade, int highGrade);
	void print();
	void addRecord(int studentNum, int grade);
	double averageRecord();
private:
	typedef listNode * studentList;
	studentList listHead;
	void deleteList(studentList &listPtr);
	studentList copiedList(const studentList original);
	bool IsValidGradeValue(int grade);
};

