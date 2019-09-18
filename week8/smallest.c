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
	int h[10],i,n,ch,smallest,s_ind;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the heap: ");
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);

	smallest=h[n/2];
	for(i=n/2;i<=n;i++)
	{
		if(h[i]<smallest)
		{
			smallest=h[i];
			s_ind=i;
		}
	}
	swap(&h[n],&h[s_ind]);
	n-=1;
	heapify(h,n);
	printf("After deletion : \n");
	for(i =1; i<=n;i++)
	{
		printf("%d ",h[i]);
	}

}