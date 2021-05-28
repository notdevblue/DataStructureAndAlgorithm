// 20219 �ѿ쿱
#include <iostream>

typedef int BTData;
struct BTreeNode
{
	BTData data;
	// Ʈ�� �ڷ� ������ ���� ������ ����� �Ѵ� �ڷ��� ����
	struct BTreeNode* left;
	// Ʈ�� ������ ���� �ڽ� ��带 ����Ű�� ���� ������ ���� ����
	struct BTreeNode* right;
	// Ʈ�� ������ ������ �ڽ� ��带 ����Ű�� ���� ������ ���� ����
};
// MakeBTreeNode() ��� �Լ��� ����� BTreeNode���� �޸𸮸� ���� �� �ֵ��� �ϰ�, �� �޸��� �ּҰ��� ��ȯ���� �� �ֵ��� �Ѵ�.

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

void DeleteBTreeNode(BTreeNode);
// DeleteBTreeNode() ��� �Լ��� ����� bt�� ����Ű�� �ִ� �޸�(BTreeNOde �ڷ��� ũ��)�� �����Ѵ�.

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}


void SetData(BTreeNode, BTData);
// SetData() ��� �Լ��� �����, ù ��° ���ڿ��� ������ ���� ����� �ּڰ��� �ְ�, �� ��° ���ڿ��� �Է½�ų �ڷ尪�� �ִ´�.

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTData GetData(BTreeNode);
BTData GetData(BTreeNode* node)
{
	return node->data;
}

BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetLeftSubTree(BTreeNode* node)
{
	return node->left;
}

BTreeNode* GetRightSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode* node)
{
	return node->right;
}

void MakeLeftSubTree(BTreeNode, BTreeNode);
// MakeLeftSubTree()��� �Լ��� ����� ù ���� ���ڷδ� �ƹ��� ��忡 �ش� �ϴ� ����� �ּڰ��� �־� �ְ�, �� ��° ���ڷδ� ���� �ڽ� ���� ������ ����� �ּڰ��� �־� �ش�.
void MakeRightSubTree(BTreeNode, BTreeNode);
// MakeRightSubTree()��� �Լ��� ����� ù ���� ���ڷδ� �ƹ��� ��忡 �ش� �ϴ� ����� �ּڰ��� �־� �ְ�, �� ��° ���ڷδ� ������ �ڽ� ���� ������ ����� �ּڰ��� �־� �ش�.

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

	main->right= sub;
}


int main()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	std::cout << GetData(GetLeftSubTree(bt1)) << std::endl;
	std::cout << GetData(GetLeftSubTree(GetLeftSubTree(bt1))) << std::endl;

	DeleteBTreeNode(bt1);
	DeleteBTreeNode(bt2);
	DeleteBTreeNode(bt3);
	DeleteBTreeNode(bt4);
}