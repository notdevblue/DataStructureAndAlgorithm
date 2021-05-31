// 20219 �ѿ쿱
#pragma once

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
BTreeNode* MakeBTreeNode(void);

// DeleteBTreeNode() ��� �Լ��� ����� bt�� ����Ű�� �ִ� �޸�(BTreeNOde �ڷ��� ũ��)�� �����Ѵ�.
void DeleteBTreeNode(BTreeNode*);

void SetData(BTreeNode*, BTData);
// SetData() ��� �Լ��� �����, ù ��° ���ڿ��� ������ ���� ����� �ּڰ��� �ְ�, �� ��° ���ڿ��� �Է½�ų �ڷ尪�� �ִ´�.

BTData GetData(BTreeNode*);

BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode*);

void MakeLeftSubTree(BTreeNode*, BTreeNode*);
// MakeLeftSubTree()��� �Լ��� ����� ù ���� ���ڷδ� �ƹ��� ��忡 �ش� �ϴ� ����� �ּڰ��� �־� �ְ�, �� ��° ���ڷδ� ���� �ڽ� ���� ������ ����� �ּڰ��� �־� �ش�.
void MakeRightSubTree(BTreeNode*, BTreeNode*);
// MakeRightSubTree()��� �Լ��� ����� ù ���� ���ڷδ� �ƹ��� ��忡 �ش� �ϴ� ����� �ּڰ��� �־� �ְ�, �� ��° ���ڷδ� ������ �ڽ� ���� ������ ����� �ּڰ��� �־� �ش�.

void PostorderTraverse(BTreeNode* bt);
void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);