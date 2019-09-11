#include <stdio.h> 
#include <stdlib.h> 
int tile(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	return tile(n-1)+tile(n-2);
}
int main()
{
	int num;
	printf("Enter size: \n");
	scanf("%d",&num);
	printf("Number of ways: %d \n",tile(num));
}