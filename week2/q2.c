#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXFAC 15
struct factor
{
	int size;
	int factor[MAXFAC+1];
	int exponent[MAXFAC+1];
};
typedef struct factor FACTOR;

void Factorise(int x, FACTOR* factorisation)
{
	int i,j=1, n=x, exp=0, no_fac=1;
	factorisation->factor[0]=1;
	factorisation->exponent[0]=1;

	for(i=2; i<=n; i++)
	{
		exp=0;
		while(n%i==0)
		{
			exp++;
			n=n/i;
		}
		if(exp>0)
		{
			factorisation->exponent[no_fac]=exp;
			factorisation->factor[no_fac]=i;
			no_fac++;
		}
	}
	factorisation->size=no_fac-1;
}

void Display(int x, FACTOR factorisation)
{
	int i;
	printf("Prime factor of %d = ",x);
	for(i=0; i<=factorisation.size;i++)
	{
		printf("%d",factorisation.factor[i]);
		if (factorisation.exponent[i]>1)
			printf("^%d",factorisation.exponent[i]);
		if(i<factorisation.size)
			printf("*");
		else
			printf("\n");
	}
}
int findGCD(int m, int n)
{
	FACTOR mfac, nfac;
	Factorise(m,&mfac);
	Display(m,mfac);

	Factorise(n,&nfac);
	Display(n,nfac);

	int min,i,j,x=1;
	i=1;
	j=1;
	while(i<=mfac.size && j<=nfac.size)
	{
		if(mfac.factor[i]<nfac.factor[j])
			i++;
		else if(nfac.factor[j] <mfac.factor[i])
			j++;
		else
		{
			min=mfac.exponent[i]>nfac.exponent[j]? nfac.exponent[j]:mfac.exponent[i];
			x=x*pow(mfac.factor[i],min);
			i++;
			j++;
		}
	}
	return x;
}

int main()
{
	int m,n;
	printf("Enter the two numbers to find the GCD of \n ");
	scanf("%d %d",&m,&n);
	printf(" GCD : %d\n", findGCD(m,n));
}