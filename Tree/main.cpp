// 20219 �ѿ쿱

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

BTreeNode* bt1 = MakeBTreeNode();
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

DeleteBTreeNode(bt);
// DeleteBTreeNode() ��� �Լ��� ����� bt�� ����Ű�� �ִ� �޸�(BTreeNOde �ڷ��� ũ��)�� �����Ѵ�.

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}


SetData(bt1, 1);
// SetData() ��� �Լ��� �����, ù ��° ���ڿ��� ������ ���� ����� �ּڰ��� �ְ�, �� ��° ���ڿ��� �Է½�ų �ڷ尪�� �ִ´�.

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

MakeLeftSubTree(bt1, bt2);
// MakeLeftSubTree()��� �Լ��� ����� ù ���� ���ڷδ� �ƹ��� ��忡 �ش� �ϴ� ����� �ּڰ��� �־� �ְ�, �� ��° ���ڷδ� ���� �ڽ� ���� ������ ����� �ּڰ��� �־� �ش�.
MakeRightSubTree(bt1, bt3);
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