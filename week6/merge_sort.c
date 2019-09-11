#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
	int len1= m-l;
	int len2= r-m+1;
	int tempa[len1], tempb[len2];
	int junk;
	// printf("Enter junk %d %d %d",l,m,r);
	// scanf("%d",&junk);
	for(int i =0; i<len1;i++)
	{
		tempa[i]=arr[l+i];
	}
	for(int i =0; i<len2;i++)
	{
		tempb[i]=arr[m+i];
	}
	int i=0,j=0,k=l;
	while(i< len1 && j < len2)
	{
		if(tempa[i]<=tempb[j])
		{
			arr[k]=tempa[i];
			i++;
		}
		else
		{
			arr[k]=tempb[j];
			j++;
		}
		k++;
	}
	while(i<len1)
	{
		arr[k]=tempa[i];
		i++;
		k++;
	}
	while(j<len2)
	{
		arr[k]=tempb[j];
		j++;
		k++;
	}
}
void merge_sort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2+1;
		merge_sort(arr,l, m-1);
		merge_sort(arr,m, r);
		merge(arr,l,m,r);
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
	merge_sort(array,0,n-1);
	for(int i=0; i<n;i++)
		printf("%d  ",array[i]);
}