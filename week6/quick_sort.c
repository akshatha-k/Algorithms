#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int* b)
{
	int temp=*b;
	*b=*a;
	*a=temp;
}
int partition(int arr[], int low, int high)
{
	int i,j,pivot =arr[high];
	i=low-1;
	for(j= low; j< high; j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}
void quick_sort(int arr[], int low, int high)
{
	if(low<high)
	{
		int p=partition(arr,low, high);
		quick_sort(arr,low, p-1);
		quick_sort(arr,p+1, high);
	}
}

int main()
{
	int *array,n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	printf("\n Enter elements of the array to be sorted : ");
	for(int i=0; i<n;i++)
		scanf("%d",&array[i]);
	printf("\n Sorted array :");
	quick_sort(array,0,n-1);
	for(int i=0; i<n;i++)
		printf("%d  ",array[i]);
}