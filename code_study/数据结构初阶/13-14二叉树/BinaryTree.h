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

// ������ǰ�����
void PreOrder(BTNode* root);

// �������������
void InOrder(BTNode* root);

// �������������
void PostOrder(BTNode* root);

//����Ԫ��
BTNode*  BuyNode(BTDataType x);

//���ض������Ľ�����
int TreeSize(BTNode* root);

//����Ҷ�ӽ�����
int TreeleafSize(BTNode* root);


