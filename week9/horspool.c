#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int t[MAX];
void shifttable(char p[])
{
	int i,j,m;
	m=strlen(p);
	for(i=0; i<MAX;i++)
		t[i]=m;
	for(j=0; j<m-2; j++)
		t[p[j]]=m-1-j;
}

void horspool(char str[],char p[])
{
	int i,j,k,m,n,flag=0;
	n=strlen(str);
	m=strlen(p);
	printf("\n Length of text= %d",n);
	printf("\n Length of pattern = %d ",m);
	i=m-1;
	while(i<n){
		k=0;
		while(k<m &&p [m-1-k]==str[i-k])
			k++;
		if(k==m){
			printf("\n The desired pattern was found at position %d \n",i-m+2);
			flag=1;
			break;
		}
		else
			i+=t[str[i]];
	}
	if(!flag)
		printf("Pattern not found in given text\n");
	
}
int main()
{
	char str[50], p[50];
	printf("ENter the main string: \n");
	gets(str);
	printf("Enter the pattern to be searched \n");
	gets(p);
	shifttable(p);
	horspool(str,p);
}