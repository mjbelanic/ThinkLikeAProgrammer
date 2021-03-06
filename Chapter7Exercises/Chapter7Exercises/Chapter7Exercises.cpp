#include "pch.h"
#include "StudenCollection.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

void exercise71();
void exercise72();
void exercise73();
int compare_ids(const void * voidA, const void * voidB);
int interpolationSearch(studentRecord arr[], int size, int target);
void exercise74();
void exercise75();
void exercise76();
void exercise77();
void exercise78();

struct listNode
{
	int studentId;
	int grade;
	string name;
};

int main()
{
    exercise71();
	exercise72();
	exercise73();
}

void exercise71() 
{
	StudentCollection studentRoster;
	studentRoster.addRecord(studentRecord{ 1001, 95, "Matthew" });
	studentRoster.addRecord(studentRecord{ 1002, 84, "Scott" });
	studentRoster.addRecord(studentRecord{ 1003, 100, "Robert" });
	studentRoster.choosePolicy(StudentCollection::policy::nameComesFirst);
	studentRecord firstRecord = studentRoster.firstStudent();
	cout << firstRecord.name << endl;
	studentRoster.choosePolicy(StudentCollection::policy::higherGrade);
	firstRecord = studentRoster.firstStudent();
	cout << firstRecord.name << endl;
}

void exercise72() 
{
	listNode node1{ 101, 95, "Matthew" };
	listNode node2{ 102, 85, "Scott" };
	listNode node3{ 103, 100, "Robert" };
	listNode node4{ 110, 90, "Drew" };
	list<listNode> studentList;
	studentList.push_back(node1);
	studentList.push_back(node2);
	studentList.push_back(node3);
	studentList.push_back(node4);
	double total = 0.00;
	list<listNode>::iterator it = studentList.begin();
	while (it != studentList.end()) {
		total += it->grade;
		it++;
	}
	double average = total / studentList.size();
	cout << average << endl;
}

void exercise73() 
{
	const int ARRAY_SIZE = 5;
	studentRecord record1 = studentRecord{ 102, 95, "Matthew" };
	studentRecord record2 = studentRecord{ 101, 85, "Scott" };
	studentRecord record3 = studentRecord{ 104, 100, "Robert" };
	studentRecord record4 = studentRecord{ 105, 90, "Drew" };
	studentRecord record5 = studentRecord{ 103, 80, "Brandon" };
	studentRecord records[ARRAY_SIZE] = { record1, record2, record3, record4, record5 };
	qsort(records, ARRAY_SIZE, sizeof(studentRecord), compare_ids);
	int index = interpolationSearch(records, ARRAY_SIZE, 103);
	cout << records[index].name << endl;
	cout << records[index].studentId << endl;
	cout << records[index].grade << endl;
}

int compare_ids(const void * voidA, const void * voidB)
{
	const studentRecord *intA = (studentRecord *)(voidA);;
	const studentRecord *intB = (studentRecord *)(voidB);;
	return intA->studentId - intB->studentId;
}

int interpolationSearch(studentRecord arr[], int size, int target)
{
	int lo = 0, hi = (size - 1);
	while (lo <= hi && target >= arr[lo].studentId && target <= arr[hi].studentId)
	{
		int pos = lo + (((double)(hi - lo) / (arr[hi].studentId - arr[lo].studentId))*(target - arr[lo].studentId));
		if (arr[pos].studentId == target) { return pos; }
		if (arr[pos].studentId < target) { lo = pos + 1; }
		else { hi = pos - 1; }
	}
	return -1;
}