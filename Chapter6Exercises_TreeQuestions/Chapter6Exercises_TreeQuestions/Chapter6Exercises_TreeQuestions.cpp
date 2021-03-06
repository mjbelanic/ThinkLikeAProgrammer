#include "pch.h"
#include <iostream>

using namespace std;

struct treeNode
{
	int data;
	treeNode * left;
	treeNode * right;
};

void exercise69();
void exercise610();
bool isHeap(treeNode * root);
bool isBST(treeNode * root);
treeNode* insertNodeRecursively(treeNode *root, int value);

int main()
{
	exercise69();
	exercise610();
}

void exercise69() 
{
	treeNode * node1 = new treeNode;
	treeNode * node2 = new treeNode;
	treeNode * node3 = new treeNode;
	treeNode * node4 = new treeNode;
	treeNode * node5 = new treeNode;
	node1->data = 10; node1->left = node2; node1->right = node3;
	node2->data = 9; node2->left = node4; node2->right = NULL;
	node3->data = 8; node3->left = NULL; node3->right = node5;
	node4->data = 8; node4->left = NULL; node4->right = NULL;
	node5->data = 3; node5->left = NULL; node5->right = NULL;
	treeNode * node6 = insertNodeRecursively(NULL, 50);
	insertNodeRecursively(node6, 100);
	insertNodeRecursively(node6, 200);
	insertNodeRecursively(node6, 5);
	cout << "TRUE" << endl;
	cout << isHeap(node1) << endl;
	cout << "FALSE" << endl;
	cout << isHeap(node6) << endl;
}

void exercise610() 
{
	treeNode * node1 = insertNodeRecursively(NULL, 50);
	treeNode * node2 = new treeNode;
	treeNode * node3 = new treeNode;
	treeNode * node4 = new treeNode;
	node2->data = 10; node2->left = node3; node2->right = NULL;
	node3->data = 3; node3->left = node4; node3->right = NULL;
	node4->data = 5; node4->left = NULL; node4->right = NULL;
	insertNodeRecursively(node1, 25);
	insertNodeRecursively(node1, 75);
	insertNodeRecursively(node1, 0);
	insertNodeRecursively(node1, 100);
	cout << "TRUE" << endl;
	cout << isBST(node1) << endl;
	cout << "FALSE" << endl;
	cout << isBST(node2) << endl;
	
}

bool isHeap(treeNode * root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else if (root->left != NULL && root->right == NULL)
	{
		if (root->data >= root->left->data) { return isHeap(root->left); }
		else { return false; }
	}
	else if (root->left == NULL && root->right != NULL)
	{
		if (root->data >= root->right->data) { return isHeap(root->right); }
		else { return false; }
	}
	else
	{
		if ((root->data >= root->left->data) && (root->data >= root->right->data))
		{ return (isHeap(root->left) && isHeap(root->right)); }
		else { return false; }
	}
}

bool isBST(treeNode * root) 
{
	if (root->left == NULL && root->right == NULL) 
	{
		return true;
	}
	else if (root->left != NULL && root->right == NULL) 
	{
		if (root->data >= root->left->data) { return isBST(root->left); }
		else { return false; }
	}
	else if (root->left == NULL && root->right != NULL) 
	{
		if (root->data < root->right->data) { return isBST(root->right); }
		else { return false; }
	}
	else 
	{
		if ((root->data >= root->left->data) && (root->data < root->right->data)) 
		{ return (isBST(root->left) && isBST(root->right)); }
		else { return false; }
	}
}

treeNode* insertNodeRecursively(treeNode *root, int value)
{
	if (root == NULL) 
	{
		treeNode* newNode = new treeNode;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if (value <= root->data) 
	{
		root->left = insertNodeRecursively(root->left, value);
	}
	if (value > root->data) 
	{
		root->right = insertNodeRecursively(root->right, value);
	}
	return root;
}
