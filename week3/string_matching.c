#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void StringMatching(char* arr, char* sub)
{
	int j;
	int a_len=strlen(arr);
	int sub_len=strlen(sub);
	for (int i = 0; i <= (a_len-sub_len); i++)
	{
		for(j=0; j<sub_len; j++)
		{
			if(arr[i+j]!=sub[j])
				break;
		}

		if(j==sub_len)
		{
			printf("String found at index %d \n",i);
		}
	}
}
int main(int argc, char const *argv[])
{
	char arr[20], sub_Arr[20];
	printf("Enter string1 and 2 \n");
	scanf("%s%s",arr,sub_Arr);
	StringMatching(arr,sub_Arr);
	return 0;
}