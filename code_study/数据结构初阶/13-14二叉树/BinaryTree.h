#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

// 二叉树前序遍历
void PreOrder(BTNode* root);

// 二叉树中序遍历
void InOrder(BTNode* root);

// 二叉树后序遍历
void PostOrder(BTNode* root);

//创建元素
BTNode*  BuyNode(BTDataType x);

//返回二叉树的结点个数
int TreeSize(BTNode* root);

//返回叶子结点个数
int TreeleafSize(BTNode* root);


