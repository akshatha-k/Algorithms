#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int m,n,t;
	printf("Enter the two numbers to find the GCD of \n ");
	scanf("%d %d",&m,&n);
	if (m>n)
		t=n;
	else
		t=m;
	while(t>0)
	{
		if(m%t==0 && n%t==0)
			break;
		else
			t=t-1;
	}
	printf(" The GCD is %d \n",t);
	
}