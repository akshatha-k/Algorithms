#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int h[],int n)
{
	int i,k,v,heapify,j;
	for(i=(n/2);i>=1;i--)
	{
		k=i;v=h[k];heapify=0;
		while(heapify==0 && 2*k<=n)
		{
			j=2*k;
			if(j<n)
				if(h[j]<h[j+1])
					j=j+1;
				if(v>=h[j])
					heapify=1;
				else
				{
					h[k]=h[j];
					k=j;
				}
		}
		h[k]=v;
	}
	return;
}
int main()
{
	int h[10],i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	heapify(h,n);
	int size=n;
	while(size>0)
	{
		swap(&h[size],&h[1]);
		printf("%d ",h[size]);
		size-=1;
		heapify(h,size);
	}

}