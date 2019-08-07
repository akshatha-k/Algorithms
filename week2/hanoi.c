#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char from_disk, char to_disk, char aux_disk)
{
	if(n==1)
	{
		printf("Disk 1 moved from %c to %c \n", from_disk,to_disk);
		return;
	}
	Hanoi(n-1,from_disk,aux_disk,to_disk);
	printf("Disk %d moved from %c to %c \n", n, from_disk,to_disk);
	Hanoi(n-1,aux_disk,to_disk,from_disk);
}
int main()
{
	int n;
	printf("Enter number of disks \n");
	scanf("%d",&n);
	Hanoi(n,'A','C','B');
}