#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 10

int count=0;
int arr[max][max];
int mincost=INT_MAX,minperm[max];

void print(int perm[],int n){
	printf("\n");
	int cost=0;
	for(int i=0;i<n;i++){

		cost+=arr[perm[i]][i];
	}
	printf("\tCost:%d",cost);
	if(cost<mincost){
		mincost=cost;
		for(int i=0;i<n;i++){
			minperm[i]=perm[i];
		}
	}

}

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

void permute(int array[],int i,int length) { 
  
  if (length==i){
     count++;
     print(array,length);
     return;
  }
 
  for (int j=i;j<length;j++) { 
     swap(array+i,array+j);
     permute(array,i+1,length);
     swap(array+i,array+j);
  }
}

int main(){
	int n;
	printf("Enter number of jobs:");
	scanf("%d",&n);
	int *per=(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		per[i]=i;
	for(int i=0;i<n;i++){
		printf("Enter cost of jobs by person %c:\n",'A'+i);
		for(int j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	}
	
	for(int i=0;i<n;i++)
		printf("%c\t",'A'+i);
	permute(per,0,n);
	printf("\nMinimum cost-assignment:\n");
	for(int i=0;i<n;i++)
		printf("%c:%d\t",'A'+i,minperm[i]+1);
	printf("\nCount:%d",count);

	
}