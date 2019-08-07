#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n,i=1;
	printf("Enter number \n ");
	scanf("%d",&n);
	while(i*i<=n)
		i++;
	i-=1;
	printf("Floor(sqrt(%d)) is %d ",n,i);
}