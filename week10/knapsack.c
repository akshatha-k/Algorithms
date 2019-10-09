#include <stdio.h>
int max(int a, int b) 
{ 
  return (a > b)? a : b; 
}
void Knapsack(int W, int weight[], int val[], int n)
{
  int i,w;
  int F[n+1][W+1];
 for (i = 0; i <= n; i++)
 {
  for (w = 0; w <= W; w++)
  {
    if (i==0 || w==0)
      F[i][w] = 0;
    else if (weight[i-1] <= w)
      F[i][w] = max(val[i-1] + F[i-1][w-weight[i-1]],  F[i-1][w]);
    else
      F[i][w] = F[i-1][w];
  }
 }
  printf("\nValue = %d \n", F[n][W]);
  printf("Items : ");
  while(n>0 && W>0)
  {
    if(F[n][W]>F[n-1][W])
    {
      printf(" val: %d  ",n);
      W-=weight[n-1];
      //printf("w:%d",W);
    }
    n--;
  }
}
int main()
{
  int val[15],weight[15], tot_weight,n;
  printf("Enter number of given items : ");
  scanf("%d",&n);
  printf("Enter the value of the items: ");
  for(int i=0; i<n;i++)
    scanf("%d",&val[i]);
  printf("Enter the weight of the corresponding items: ");
  for(int i=0; i<n;i++)
    scanf("%d",&weight[i]);
  printf("Enter the total value of the Knapsack: ");
  scanf("%d",&tot_weight);
  Knapsack(tot_weight,weight,val,n);
  return 0;

}

//60,100,120   10,20,30 50