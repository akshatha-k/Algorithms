#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount=0;
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
	arra
	for(int i=0; i<100; i++)
	{
		n=rand()%1000;
		printf("%d",n);

	for(int i=0; i<n;i++)
		array[i]=rand()%1000;
	//printf("\n Sorted array :");
	quick_sort(array,0,n-1);
	// for(int i=0; i<n;i++)
	// 	printf("%d  ",array[i]);
	printf("op: %d",opcount);
}
}