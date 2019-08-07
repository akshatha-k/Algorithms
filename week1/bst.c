#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

NODE insert(NODE node, int val)
{
	if(node== NULL)
	{
		NODE temp= (NODE)malloc(sizeof(struct node));
		temp->key=val;
		temp->left=NULL;
		temp->right=NULL;
		node=temp;
	}
	else if(node->key== val)
	{
		printf("key found \n");
		return;
	}
	else if(val > node->key)
	{
		node->right=insert(node->right, val);
	}
	else if(val < node->key)
	{
		node->left=insert(node->left, val);
	}
	return node;
}

void inorder(NODE node)
{
	if (node== NULL)
	{
		return;
	}
	inorder(node->left);

	printf(" %d ",node->key);

	inorder(node->right);	
}

void preorder(NODE node)
{
	if (node== NULL)
	{
		return;
	}
	printf(" %d ",node->key);

	inorder(node->left);

	inorder(node->right);

	
}

void postorder(NODE node)
{
	if (node== NULL)
	{
		return;
	}
	inorder(node->left);

	inorder(node->right);

	printf(" %d ",node->key);
}