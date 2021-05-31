// 20219 한우엽
#include "BinaryTree.h"
#include <iostream>

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	// 동적 메모리를 할당하는 부분이다.


	nd->left = NULL;
	nd->right = NULL;
	// BTreeNode 형으로 생성된 nd의 left와 right 포인터에는 현재 대입되는 다른 노드의 주소가 없기 때문에  NULL 값을 넣는다. 이후에 자식 노드가 있는 경우에 그 주솟값을 여기에 넣게 된다.
	return nd;
	// nd 에 대한 정의가 모드 끝났으면 nd 의 주솟값을 반환해준다.
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
		// 이미 자식 노드에 할당된 노드가 있다면, 기존 것을 삭제한다.
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