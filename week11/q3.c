#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node{
	int key;
	float freq;
	struct node * left,*right;
};

typedef struct node *NODE;
NODE trees[26];

void preorder(NODE root){
	if(root!=NULL){
		printf("%c %f\n",root->key,root->freq);
		preorder(root->left);
		
		preorder(root->right);
	}	
}
NODE huffman(int charset[],float freq[],int n){
	
	for(int i=0;i<n;i++){
		NODE newnode=(NODE)malloc(sizeof(struct node));
		newnode->key=charset[i];
		newnode->freq=freq[i];
		newnode->left=newnode->right=NULL;
		trees[i]=(NODE)malloc(sizeof(struct node));
		trees[i]->key='I';
		trees[i]->freq=0;
		trees[i]->left=newnode;
	}
	NODE min1=trees[0]->left;
	int i_min1=0;
	int i_min2=1;
	NODE min2=trees[1]->left;
	if(min1->freq > min2->freq){
		NODE temp=min1;
		min1=min2;
		min2=temp;
		i_min1=1;
		i_min2=0;
	}
	int count=n;
	while(count>1){
		for(int i=0;i<n;i++){
			if(trees[i]->left!=NULL){
				NODE temp=trees[i]->left;
				if(temp->freq < min2->freq && temp!=min1 && temp!=min2){
					if(temp->freq < min1->freq){
						min2=min1;
						min1=temp;
						
						i_min2=i_min1;
						i_min1=i;
					}
					else{
						min2=temp;
						i_min2=i;
					}
				}
			}
		}
		NODE newroot=(NODE)malloc(sizeof(struct node));
		newroot->key='I';
		newroot->freq=min1->freq + min2->freq;
		newroot->left=min1;
		newroot->right=min2;
		trees[i_min1]->left=newroot;
		trees[i_min2]->left=NULL;
		min1=(NODE)malloc(sizeof(struct node));
		min1->freq=INT_MAX;
		min2=(NODE)malloc(sizeof(struct node));
		min2->freq=INT_MAX;			
		count--;
	}
	for(int i=0;i<n;i++)
		if(trees[i]->left!=NULL)
			return trees[i]->left;
}
int main(){
	int n,charset[26];
	float freq[26];
	printf("Number of characters:");
	scanf("%d",&n);
	printf("Enter characters and frequency:");
	for(int i=0;i<n;i++){
		char x[2];
		scanf("%s",x);
		charset[i]=(int)x[0];
		scanf("%f",&freq[i]);
	}
	NODE result=huffman(charset,freq,n);
	printf("\n");
	preorder(result);
}