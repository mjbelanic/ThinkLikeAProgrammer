#pragma once
#include <string>
#include <iostream>
using namespace std;

struct studentRecord
{
	int studentId;
	int grade;
	string name;
};

class StudentCollection;

typedef bool (StudentCollection::*firstStudentPolicy) (studentRecord r1, studentRecord r2);

class StudentCollection
{
private:
	struct studentNode
	{
		studentRecord studentData;
		studentNode* next;
	};
	bool higherGrade(studentRecord r1, studentRecord r2)
	{
		return r1.grade > r2.grade;
	}
	bool lowerStudentNumber(studentRecord r1, studentRecord r2)
	{
		return r1.studentId < r2.studentId;
	}
	bool nameComesFirst(studentRecord r1, studentRecord r2)
	{
		return strcmp(r1.name.c_str(), r2.name.c_str()) < 0;
	}
public:
	StudentCollection();
	~StudentCollection();
	StudentCollection& operator=(const StudentCollection& rhs);
	void setFirstStudentPolicy(firstStudentPolicy f);
	void print();
	void addRecord(studentRecord newStudent);
	enum class policy
	{
		higherGrade,
		lowerStudentNumber,
		nameComesFirst
	};
	void choosePolicy(policy p);
	studentRecord firstStudent();
private:
	typedef studentNode * studentList;
	studentList listHead;
	firstStudentPolicy currentPolicy;
	void deleteList(studentList &listPtr);
	studentList copiedList(const studentList original);
	bool IsValidGradeValue(int grade);
};

