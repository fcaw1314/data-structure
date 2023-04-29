#define _CRT_SECURE_NO_WARNINGS 1

#include "BinaryTree.h"


BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail:");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}


// ������ǰ�����
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

// �������������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

// �������������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	
	PostOrder(root->right);
	printf("%d ", root->data);
}

//���ض������Ľ�����
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

//����Ҷ�ӽ�����
int TreeleafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeleafSize(root->left) + TreeleafSize(root->right);
}

//�����������
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leafHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leafHeight > rightHeight ? leafHeight + 1 : rightHeight + 1;
}

//��k��Ľ����� k >= 1
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

//����������ֵΪx��ֵ
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if(ret2)
		return ret2;
		
	return NULL;
}

// ����������
void TreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);

}


////�������
//void LevelOrder(BTNode* root)
//{
//
//}