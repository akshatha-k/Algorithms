#include <stdio.h>
#include <stdlib.h>

int exponent(int a, int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return exponent(a, n/2)*exponent(a,n/2);
	else
		return a*exponent(a,n/2)*exponent(a,n/2);
}
int main()
{
	int b, exp;
	printf("Enter the base and exponent\n");
	scanf("%d %d",&b,&exp);
	printf("Result : %d \n", exponent(b,exp));
	return 0;
}