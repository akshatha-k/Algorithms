#include <stdio.h>
#include <stdlib.h>

void change(int d[], int m, int n)
{
	int *count=(int*)malloc(sizeof(int)*n);
	for(int i=0; i<m;i++)
	{
		count[i]=n/d[i];
		n=n%d[i];
	}
	if(n==0)
	{
		printf("The number of coins : \n");
		for(int i=0; i<m;i++)
			printf(" Amount %d :%d \n",d[i],count[i]);
	}
	else
		printf("NO SOLUTION \n");

}
int main()
{
	int n,arr[10],amt;
	printf("Enter number of coin denominations \n");
	scanf("%d",&n);
	printf("Enter coin denominations \n");
	for(int i=0; i<n;i++)
		scanf("%d",&arr[i]);
	printf("Enter Amount :\n");
	scanf("%d",&amt);
	change(arr,n,amt);
}