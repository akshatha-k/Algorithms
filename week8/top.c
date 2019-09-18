#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void top_heapify(int h[],int n)
{
	int k=n/2;
	while(k>0)
	{
			if(h[n]> h[k])
				swap(&h[k],&h[n]);
			n=k;
			k/=2;
	}

	
}
int main()
{
	int arr[20],i, n;
	printf("Enter number of elements \n");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		top_heapify(arr,i);
	}
	printf("\nheap : ");
	for(i=1;i<=n;i++)
	{
		printf("%d  ",arr[i]);
	}
}