// 20219 �ѿ쿱
#include <iostream>
#include "BinaryTree.h"



int main()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeLeftSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);

	PreorderTraverse(bt1);
	std::cout << std::endl;

	InorderTraverse(bt1);
	std::cout << std::endl;

	PostorderTraverse(bt1);
	std::cout << std::endl;
}