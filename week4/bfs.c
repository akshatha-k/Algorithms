#include<stdio.h>
#include<stdlib.h>

struct Node{
	char label;
	struct Node * link;
};

typedef struct Node * Nodeptr;


void addEdge(Nodeptr list[],char x,char y){
	Nodeptr temp=list[x-'a'];
	while(temp->link!=NULL){
		temp=temp->link;
		if(temp->label==y){
			printf("Edge exists\n");
			return;
		}
	}
	Nodeptr newnode=(Nodeptr)malloc(sizeof(struct Node));
	newnode->label=y;
	newnode->link=NULL;
	temp->link=newnode;
	
}

void bfs(Nodeptr list[],int visited[]){
	printf("\nBreadth first traversal order:\n");
	for(int i=0;i<length;i++){
		Nodeptr temp=list[i];
		while(temp!=NULL){
			if(visited[temp->label-'a']==0){
				printf("%c\t",temp->label);
				visited[temp->label-'a']=1;
			}
			temp=temp->link;
		}
	}
}

int main(){
	int length;
	printf("Enter number of nodes \n");	
	scanf("%d",&length);
	Nodeptr list[length];
	int visited[length]={0};
	for(int i=0;i<length;i++){
		list[i]=(Nodeptr)malloc(sizeof(struct Node));
		list[i]->link=NULL;
		list[i]->label='a'+i;
	}
	int ch=0;
	while(ch!=3){
		printf("\n1:Add edge\n2:Traverse\n3:Exit\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			char x[2],y[2];
			printf("Enter edge to add:\n");
			scanf("%s",x);
			scanf("%s",y);
			addEdge(list,x[0],y[0]);
			
		}
		if(ch==2){
			//dispadj(list);
			bfs(list,visited);
		}
	}
return 0;	
}