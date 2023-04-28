
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


// 二叉树前序遍历
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

// 二叉树中序遍历
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

// 二叉树后序遍历
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

//返回二叉树的结点个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

//返回叶子结点个数
int TreeleafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeleafSize(root->left) + TreeleafSize(root->right);
}

//返回树的深度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leafHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leafHeight > rightHeight ? leafHeight + 1 : rightHeight + 1;
}

//第k层的结点个数 k >= 1
int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}