
#include <stdio.h> 
#include <stdlib.h> 

struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 
struct node* insert(struct node* node, int val)
{
  if(node== NULL)
  {
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    node=temp;
  }
  else if(node->data== val)
  {
    printf("key found \n");
    return;
  }
  else if(val > node->data)
  {
    node->right=insert(node->right, val);
  }
  else if(val < node->data)
  {
    node->left=insert(node->left, val);
  }
  return node;
}
int max(int a, int b) 
{ 
  return (a >= b)? a: b; 
} 
int height(struct node* node) 
{ 

   if(node == NULL) 
       return 0; 

   return 1 + max(height(node->left), height(node->right)); 
}  


int diameter(struct node * tree) 
{ 

   if (tree == NULL) 
     return 0; 

  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  

  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  


struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
  
    

int main() 
{ 
  int val= 0;
  struct node *root = NULL;
  while(1)
  {
    printf("\nEnter value: ");
    scanf("%d",&val);
    if(val==-1)
      break;
    root= insert(root, val);
  }
  
  printf("Diameter of the given binary tree is %d\n", diameter(root)); 
  
  getchar(); 
  return 0; 
} 
