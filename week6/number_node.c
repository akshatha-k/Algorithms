
#include <stdio.h> 
#include <stdlib.h> 

typedef struct node 
{ 
    int data; 
    struct node* left, *right; 
}node; 

node* insert()
{
  int val;
  printf("Enter value (-1 to exit): \n");
  scanf("%d",&val);
  if(val==-1)
    return NULL;
  node* n=(node*)malloc(sizeof(node));
  n->data=val;
  printf("Enter left child of %d: \n", val);
  n->left= insert();
  printf("Enter right child of %d: \n", val);
  n->right= insert();
  return n;
}
int numberNodes(node* root)
{
  if(root==NULL)
    return 0;
  return numberNodes(root->left)+numberNodes(root->right)+1;
}
int main()
{
  node* root= insert();
  printf("The number of nodes in the binary tree is: %d \n",numberNodes(root));
  return 0;
}