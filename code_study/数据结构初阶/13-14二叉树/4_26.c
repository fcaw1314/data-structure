#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"




int main()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;

	PreOrder(n1);
	printf("\n");
	InOrder(n1);
	printf("\n");
    PostOrder(n1);
	printf("\n");


	printf("TreeSize: %d \n", TreeSize(n1));
	printf("TreeleafSize: %d \n", TreeleafSize(n1));

	return 0;
}

