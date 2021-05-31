// 20219 �ѿ쿱
#include "BinaryTree.h"
#include <iostream>

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	// ���� �޸𸮸� �Ҵ��ϴ� �κ��̴�.


	nd->left = NULL;
	nd->right = NULL;
	// BTreeNode ������ ������ nd�� left�� right �����Ϳ��� ���� ���ԵǴ� �ٸ� ����� �ּҰ� ���� ������  NULL ���� �ִ´�. ���Ŀ� �ڽ� ��尡 �ִ� ��쿡 �� �ּڰ��� ���⿡ �ְ� �ȴ�.
	return nd;
	// nd �� ���� ���ǰ� ��� �������� nd �� �ּڰ��� ��ȯ���ش�.
}

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTData GetData(BTreeNode* node)
{
	return node->data;
}

BTreeNode* GetLeftSubTree(BTreeNode* node)
{
	return node->left;
}

BTreeNode* GetRightSubTree(BTreeNode* node)
{
	return node->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		// �̹� �ڽ� ��忡 �Ҵ�� ��尡 �ִٸ�, ���� ���� �����Ѵ�.
	{
		delete main->left;
	}

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
	{
		delete main->right;
	}

	main->right = sub;
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);

	std::cout << bt->data << std::endl;
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	std::cout << bt->data << std::endl;

	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
	{
		return;
	}

	InorderTraverse(bt->left);
	std::cout << bt->data << std::endl;
	InorderTraverse(bt->right);
}