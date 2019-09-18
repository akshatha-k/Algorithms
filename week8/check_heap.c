#include <stdio.h>
#include <stdlib.h>

void check_heap(int arr[], int n)
{
	int i=1;
	while(2*i<=n && (2*i+1)<=n)
	{
		if(arr[i]<arr[2*i] || arr[i]<arr[2*i+1])
		{
			printf("Not a heap !\n");
			exit(0);
		}
	}
	printf("wohoo \n");
}
int main()
{
	int h[10],i,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	check_heap(h,n);

}