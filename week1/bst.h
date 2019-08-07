#ifndef _bst_h
#define _bst_h

struct node
{
	struct node* left;
	struct node* right;
	int key;
};

typedef struct node* NODE;

NODE insert(NODE node, int val);
void inorder(NODE node);
void preorder(NODE node);
void postorder(NODE node);



#endif