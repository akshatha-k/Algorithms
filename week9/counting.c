#include  <stdio.h>
void counting_sort(int a[], int k, int n)
{
	int i,j;
	int b[15],c[50];
	for(i=0; i<=k;i++)
		c[i]=0;
	for(j=1; j<=n;j++)
		c[a[j]]=c[a[j]]+1;
	for(i=1;i<=k;i++)
		c[i]=c[i]+c[i-1];
	for(j=n;j>=1; j--)
	{
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1;
	}
	printf("Sorted array is : \n");
	for(i=1; i<=n; i++)
		printf("%d ",b[i]);
}

int main()
{
	int n,k=0,a[15],i;
	printf("ENter the size of the array : ");
	scanf("%d",&n);
	printf("\n Enter elements ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	
		if(a[i]>k)
		{
			k=a[i];
		}
	}
	counting_sort(a,k,n);
}