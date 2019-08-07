#include <stdio.h>
#include <stdlib.h>

void swapNum(int *x, int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void BubbleSort(int arr[], int n)
{
	for(int i=0 ; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j]>arr[j+1])
				swapNum(&arr[j],&arr[j+1]);
		}
	}
}

void printArray(int arr[], int n)
{
	for(int i= 0; i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[20], n;
	printf("Enter array size \n");
	scanf("%d",&n);
	printf("Enter the numbers to be sorted \n");
	for(int i=0; i<n;i++)
		scanf("%d",&arr[i]);
	BubbleSort(arr,n);
	printf("Array after sorting : \n");
	printArray(arr,n);

}