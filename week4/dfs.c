
#include<stdio.h>
#include<stdlib.h>
#define length 4
int matrix[length][length]={0};
int visited[length];
char pop[length];
int ind=0;

void dispmat(int mat[][length]){
	printf("\n\t");
	for(int i=0;i<length;i++)
		printf("%c\t",'a'+i);
	printf("\n");
	printf("\n");
	for(int i=0;i<length;i++){
		printf("%c\t",'a'+i);
		for(int j=0;j<length;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}


void addEdgemat(int matrix[][length],char x,char y){
	matrix[x-'a'][y-'a']=1;
}

void DFS(int i)
{	
    int j;
    printf("%c ",i+'a');
    visited[i]=1;
    
    for(j=0;j<length;j++)
       if(!visited[j]&&matrix[i][j]==1){
            DFS(j);
            
            //printf("\nPop %c",i+'a');

       }
    pop[ind++]=i+'a';   
}

int main(){
	int ch=0;
	while(ch!=3){
		printf("\n1:Add edge\n2:Display\n3:Exit\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1){
			char x[2],y[2];
			printf("Enter edge to add:\n");
			scanf("%s",x);
			scanf("%s",y);
			
			addEdgemat(matrix,x[0],y[0]);
		}
		if(ch==2){
			
			dispmat(matrix);
			printf("Push order:");
			for(int i=0;i<length;i++)
				if(visited[i]==0)
					DFS(i);
			printf("\nPop order:");
			for(int i=0;i<length;i++)
				printf("%c ",pop[i]);
			printf("\n");
		}
	}
return 0;	
}
