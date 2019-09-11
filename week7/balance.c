#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int info;
	struct node *left, *right;
	int balance, height;
}NODE;
int max(int a, int b)
{
	return (a>b?a:b);
}
int height(NODE* node) 
{ 

   if(node == NULL) 
       return 0; 

   return 1 + max(height(node->left), height(node->right)); 
}  

int getBalance(NODE* node)
{
	if(node==NULL)
		return 0;
	return height(node->left) - height(node->right);
}
void inorder(NODE* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d   ",ptr->info);
		printf("Balance fac: %d \n",getBalance(ptr));
		inorder(ptr->right);
	}
}
void preorder(NODE* ptr)
{
	if(ptr!=NULL)
	{
		printf("%d   ",ptr->info);
		printf("Balance fac: %d \n",getBalance(ptr));
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
NODE* rightRotate(NODE* node)
{
	NODE* x=node->left;
	NODE* temp=x->right;
	x->right =node;
	node->left= temp;

	node->height =max(height(node->left),height(node->right))+1;
	x->height =max(height(x->left),height(x->right))+1;
	return x;
}

NODE* leftRotate(NODE* node)
{
	NODE* x=node->right;
	NODE* temp=x->left;
	x->left =node;
	node->right= temp;

	node->height =max(height(node->left),height(node->right))+1;
	x->height =max(height(x->left),height(x->right))+1;
	return x;
}

NODE* create(NODE *bnode, int x)
{
	NODE *getnode;
	if(bnode==NULL)
	{
		bnode=(NODE*)malloc(sizeof(NODE));
		bnode->info=x;
		bnode->left=bnode->right=NULL;
	}
	else if(x>bnode -> info)
		bnode->right = create(bnode-> right, x);
	else if(x<bnode-> info)
		bnode->left=create(bnode->left, x);
	else
	{
		printf("Duplicate node \n");
		exit(0);
	}
	bnode->balance=getBalance(bnode);
	bnode->height=height(bnode);
	if(bnode->balance >1 && x < bnode ->left->info)
		return rightRotate(bnode);
	if(bnode->balance < -1 && x > bnode->right->info)
		return leftRotate(bnode);
	if(bnode->balance >1 && x > bnode->left->info)
	{
		bnode->left =leftRotate(bnode->left);
		return rightRotate(bnode);
	}
	if(bnode->balance <-1 && x < bnode->right->info)
	{
		bnode->right =rightRotate(bnode->right);
		return leftRotate(bnode);
	}
	// printf("\nInorder traversal : \n");
	// inorder(bnode);
	return(bnode);

}

void main()
{
	int ch,x;
	NODE *root;
	root=NULL;
	while(1)
	{
		printf(" 1. Insert \n 2. Traverse \n 3. Exit \n");
		printf("Enter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter node : \n");
					scanf("%d",&x);
					root=create(root, x);
					break;
			case 2: printf("\nInorder traversal : \n");
					inorder(root);
					printf("\nPreorder traversal : \n");
					preorder(root);
					break;
			case 3: exit(0);
		}
	}
}
