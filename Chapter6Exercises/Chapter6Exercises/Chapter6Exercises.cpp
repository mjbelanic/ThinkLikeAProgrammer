#include "pch.h"
#include <iostream>
using namespace std;

struct listNode 
{
	int num;
	listNode * next;
};
typedef listNode * numCollection;
void exercise61();
int sumIterativeMethod(int nums[], int len);
int sumRecursiveMethod(int nums[], int len);
void exercise62();
bool isOddParityIterative(int bitString[], int len);
bool isOddParityRecursive(int bitString[], int len);
void exercise63();
int findTargetIterative(int nums[], int len, int target);
int findTargetRecursive(int nums[], int len, int target);
void exercise64();
int findPrimeTotal(int nums[], int len);
bool isPrimeRecursive(int num, int checker);
bool isTotalDivisible(int nums[], int total, int len);
void exercise65();
int listSumIterativeMethod(numCollection numList);
int listSumRecurviseMethod(numCollection numList);
void exercise66();
bool isListOddParityIterative(numCollection numList);
bool isListOddParityRecursive(numCollection numList);
void exercise67();
int listFindTargetIterative(numCollection numList, int target);
int listFindTargetRecursive(numCollection numList, int target);
void exercise68();
void deleteListRecursive(numCollection& numList);

int main()
{
	//exercise61();
	//exercise62();
	//exercise63();
	//exercise64();
	//exercise65();
	//exercise66();
	//exercise67();
	//exercise68();
}

void exercise61() 
{
	const int len = 10;
	int nums[len] = { 1, -2, 0, 7, 8, 5, 100, 4, -9, -12 };
	int iterativeTotal = sumIterativeMethod(nums, len);
	cout << iterativeTotal << endl;
	int recursiveTotal = sumRecursiveMethod(nums, len);
	cout << recursiveTotal << endl;
}

int sumIterativeMethod(int nums[], int len) 
{
	int total = 0;
	for (int i = 0; i < len; i++) 
	{
		if (nums[i] >= 0) {	total += nums[i]; }
	}
	return total;
}

int sumRecursiveMethod(int nums[], int len) 
{
	int count = 0;
	if (len == 0) { return 0; }
	if (nums[len - 1] >= 0) { count = nums[len - 1]; }
	return count + sumRecursiveMethod(nums, len - 1);
}

void exercise62() 
{
	const int size1 = 10; 
	const int size2 = 5;
	int bitString1[size1] = { 1,0,0,0,1,1,0,0,1,0 };
	int bitString2[size2] = { 1,1,1,0,0 };
	cout << "False:" << endl;
	cout << isOddParityIterative(bitString1, size1) << endl;
	cout << isOddParityRecursive(bitString1, size1) << endl;
	cout << "True:" << endl;
	cout << isOddParityIterative(bitString2, size2) << endl;
	cout << isOddParityRecursive(bitString2, size2) << endl;
}

bool isOddParityIterative(int bitString[], int len) 
{
	bool isOdd = false;
	for (int i = 0; i < len; i++) 
	{
		if (bitString[i] == 1) 
		{
			if (isOdd) { isOdd = false; }
			else { isOdd = true; }
		}
	}
	return isOdd;
}

bool isOddParityRecursive(int bitString[], int len) 
{
	if (len == 0) { return false; }
	bool isOdd = isOddParityRecursive(bitString, len-1);
	if (bitString[len - 1] == 1) 
	{
		if (isOdd) { isOdd = false; }
		else { isOdd = true; }
	}
	return isOdd;
}

void exercise63() 
{
	const int len = 10;
	int nums1[len] = { 12, 200, 12, 78, -11, 21, 12, 452, -3, -12 };
	int nums2[len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int target = 12;
	int numOfTargets1 = findTargetIterative(nums1, len, target);
	int numOfTargets2 = findTargetIterative(nums2, len, target);
	int numOfTargets3 = findTargetRecursive(nums1, len, target);
	int numOfTargets4 = findTargetRecursive(nums2, len, target);
	cout << numOfTargets1 << endl; cout << numOfTargets2 << endl;
	cout << numOfTargets3 << endl; cout << numOfTargets4 << endl;
}

int findTargetIterative(int nums[], int len, int target)
{
	int count = 0;
	for (int i = 0; i < len; i++) 
	{
		if (nums[i] == target) { count++; }
	}
	return count;
}

int findTargetRecursive(int nums[], int len, int target) 
{
	int count = 0;
	if (len == 0) { return 0; }
	if (nums[len - 1] == target) { count++; }
	return count + findTargetRecursive(nums, len - 1, target);
}

// Given an array arr[], the task is to check whether the sum of primes in the array
// is divisible by any of the primes in the array. If it is print YES, otherwise print NO.
// Examples:
// arr[] = {2,3} -> NO 2+3 = 5, 5 is not divisible by 2 or 3
// arr[] = {1,2,3,4,5} -> YES 2+3+5=10, 10 is divisible by 2,5
void exercise64() 
{
	const int len1 = 2;
	const int len2 = 5;
	int nums1[len1] = { 2, 3 };
	int nums2[len2] = { 1,2,3,4,5 };
	int primeTotal1 = findPrimeTotal(nums1, len1);
	int primeTotal2 = findPrimeTotal(nums2, len2);
	bool total1Divisible = isTotalDivisible(nums1, primeTotal1, len1);
	bool total2Divisible = isTotalDivisible(nums2, primeTotal2, len2);
	if (total1Divisible == true) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	if (total2Divisible == true) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
}

int findPrimeTotal(int nums[], int len)
{
	int total = 0;
	if (len == 0) { return 0; }
	if (isPrimeRecursive(nums[len-1], nums[len - 1]-1)) { total += nums[len-1]; };
	return total + findPrimeTotal(nums, len - 1);
}

bool isPrimeRecursive(int num, int checker)
{
	if (checker == 0) { return false; }
	if (checker == 1) { return true; }
	if (num % checker == 0) { return false; }
	isPrimeRecursive(num, checker - 1);
}

bool isTotalDivisible(int nums[], int total, int len)
{
	if (len == 0) { return false; }
	bool passes = isOddParityRecursive(nums, len - 1);
	if (total % nums[len - 1] == 0) { passes = true; }
	else { passes = false; }
	return passes;
}

void exercise65()
{
	numCollection numList;
	listNode * node1 = new listNode; node1->num = -6; listNode * node2 = new listNode; node2->num = 2;
	listNode * node3 = new listNode; node3->num = 0; listNode * node4 = new listNode; node4->num = 3;
	listNode * node5 = new listNode; node5->num = 1; listNode * node6 = new listNode; node6->num = -5;
	numList = node1; node1->next = node2; node2->next = node3; node3->next = node4; 
	node4->next = node5; node5->next = node6; node6->next = NULL;
	cout << listSumIterativeMethod(numList) << endl;
	cout << listSumRecurviseMethod(numList) << endl;
}

int listSumIterativeMethod(numCollection numList) 
{
	int total = 0;
	while (numList->next != NULL) 
	{
		if (numList->num >= 0) { total += numList->num; }
		numList = numList->next;
	}
	return total;
}

int listSumRecurviseMethod(numCollection numList) 
{
	int total = 0;
	if (numList == NULL) { return total; }
	if (numList->num >= 0) { total = numList->num; }
	return total + listSumRecurviseMethod(numList->next);
}

void exercise66() 
{
	numCollection numList1;
	numCollection numList2;
	listNode * node1 = new listNode; node1->num = 0; listNode * node2 = new listNode; node2->num = 1;
	listNode * node3 = new listNode; node3->num = 0; listNode * node4 = new listNode; node4->num = 1;
	listNode * node5 = new listNode; node5->num = 1; listNode * node6 = new listNode; node6->num = 0;
	numList1 = node1; node1->next = node2; node2->next = node3; node3->next = NULL;
	numList2 = node4; node4->next = node5; node5->next = node6; node6->next = NULL;
	cout << "False:" << endl;
	cout << isListOddParityIterative(numList2) << endl;
	cout << isListOddParityRecursive(numList2) << endl;
	cout << "True:" << endl;
	cout << isListOddParityIterative(numList1) << endl;
	cout << isListOddParityRecursive(numList1) << endl;
}

bool isListOddParityIterative(numCollection numList) 
{
	int count = 0;
	bool isOdd = false;
	while (numList != NULL) 
	{
		if (numList->num == 1) 
		{
			if (isOdd == true) { isOdd = false; }
			else { isOdd = true; }
		}
		numList = numList->next;
	}
	return isOdd;
}

bool isListOddParityRecursive(numCollection numList) 
{
	if (numList == NULL) { return false; }
	bool isOdd = isListOddParityRecursive(numList->next);
	if (numList->num == 1)
	{
		if (isOdd) { isOdd = false; }
		else { isOdd = true; }
	}
	return isOdd;
}

void exercise67() 
{
	numCollection numList1;
	numCollection numList2;
	listNode * node1 = new listNode; node1->num = -6; listNode * node2 = new listNode; node2->num = 21;
	listNode * node3 = new listNode; node3->num = 12; listNode * node4 = new listNode; node4->num = 12;
	listNode * node5 = new listNode; node5->num = -12; listNode * node6 = new listNode; node6->num = 22;
	listNode * node7 = new listNode; node7->num = 12; listNode * node8 = new listNode; node8->num = -212;
	numList1 = node1; node1->next = node2; node2->next = node3; node3->next = node4; node4->next = node5;
	node5->next = node6; node6->next = node7; node7->next = node8; node8->next = NULL;
	listNode * node9 = new listNode; node9->num = NULL; node9->next = NULL; numList2 = node9;
	cout << listFindTargetIterative(numList1, 12) << endl;
	cout << listFindTargetRecursive(numList1, 12) << endl;
	cout << listFindTargetIterative(numList2, 12) << endl;
	cout << listFindTargetRecursive(numList2, 12) << endl;
}

int listFindTargetIterative(numCollection numList, int target)
{
	int total = 0;
	while (numList != NULL) 
	{
		if (numList->num == target) { total++; }
		numList = numList->next;
	}
	return total;
}

int listFindTargetRecursive(numCollection numList, int target)
{
	int total = 0;
	if (numList == NULL) { return total; }
	if (numList->num == target) { total++; }
	return total + listFindTargetRecursive(numList->next, target);
}

//Delete the given linked list using recursion
void exercise68() 
{
	numCollection numList;
	listNode * node1 = new listNode; node1->num = -6; listNode * node2 = new listNode; node2->num = 2;
	listNode * node3 = new listNode; node3->num = 0; listNode * node4 = new listNode; node4->num = 3;
	listNode * node5 = new listNode; node5->num = 1; listNode * node6 = new listNode; node6->num = -5;
	numList = node1; node1->next = node2; node2->next = node3; node3->next = node4;
	node4->next = node5; node5->next = node6; node6->next = NULL;
	deleteListRecursive(numList);
	int count = 0;
	while (numList != NULL)
	{
		count++;
		cout << numList->num << endl;
		numList = numList->next;
	}
	cout << count << endl;
}

void deleteListRecursive(numCollection& numList) 
{
	if (numList == NULL) { return; }
	while (numList != NULL) 
	{
		listNode * temp = numList;
		numList = numList->next;
		delete temp;
		deleteListRecursive(numList);
	}
}