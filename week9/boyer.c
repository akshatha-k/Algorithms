#include<limits.h>
#include<string.h>
#include<stdio.h>
#define NOM 256

int max(int a,int b)
{
	return a>b?a:b;
}

void badChar(char *str,int size, int badchar[NOM])
{
	int i;
	for(i=0;i<NOM;i++)
		badchar[i]=-1;
	for (int i = 0; i <size; i++)
	{
		badchar[(int)str[i]]=i;
	}
}

void search(char *txt,char *pat)
{
	int m=strlen(pat);
	int n=strlen(txt);

	int badchar[NOM];
	badChar(pat,m,badchar);
	int s=0;

	while(s<=(n-m))
	{
		int j=m-1;

		while(j>=0&&pat[j]==txt[s+j])
			j--;
	if(j<0)
	{
		printf("pattern occurs at shift=%d",s);

		s+=(s+m<n)?m-badchar[txt[s+m]]:1;
	}
	else
	s+=max(1,j-badchar[txt[s+j]]);	
	}
}

int main()
{
	char txt[]="abaaacd";
	char pat[]="aba";
	search(txt,pat);
}