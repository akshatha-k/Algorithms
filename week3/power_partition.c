#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int arr[20], n, totsum=0,flag, sum;
	printf("Enter set size \n");
	scanf("%d",&n);
	printf("Enter the numbers\n");
	for(int i=0; i<n;i++)
		scanf("%d",&arr[i]);

	int pow_size=pow(2,n-1);

	for (int i = 0; i < n; i++) 
       totsum += arr[i]; 

    if (totsum%2 != 0) 
    {
       printf("Can't be partitioned \n");
       exit(0);
    }

	for(int i=0; i <pow_size; i++)
	{
		sum=0;
		for(int j=0; j<n;j++)
		{
			if(i & (1<<j))
				sum+=arr[j];
		}
		if(sum== (totsum-sum))
		{
			flag=1;
			for(int j=0; j<n;j++)
			{
				if(i & (1<<j))
					printf("%d ",arr[j]);
			}
			printf("\n");
			for(int j=0; j<n;j++)
			{
				if(!(i & (1<<j)))
					printf("%d ",arr[j]);
			}
			printf("\n");
		}
	}
	if(flag==0)
		printf("Can't be partitioned \n");
	return 0;
}