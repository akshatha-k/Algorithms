#include <stdio.h>
int weights[15],val[15], F[15][15],n;
int max(int a, int b) 
{ 
  return (a > b)? a : b; 
}
int MFKnapsack(int i, int j)
{
  int value;
  if(F[i][j]<0)
  {
    if(j<weights[i-1])
      value=MFKnapsack(i-1,j);
    else
      value=max(MFKnapsack(i-1,j),val[i-1]+MFKnapsack(i-1, j-weights[i-1]));
    F[i][j]=value;
  }
  return F[i][j];
}
int main()
{
  int W;
  printf("Enter number of given items : ");
  scanf("%d",&n);
  printf("Enter the value of the items: ");
  for(int i=0; i<n;i++)
    scanf("%d",&val[i]);
  printf("Enter the weight of the corresponding items: ");
  for(int i=0; i<n;i++)
    scanf("%d",&weights[i]);
  printf("Enter the total value of the Knapsack: ");
  scanf("%d",&W);
  for(int i=0; i<=n;i++)
  {
    for(int j=0; j<=W;j++)
    {
      if(i==0 || j==0)
        F[i][j]=0;
      else
        F[i][j]=-1;
    }
  }
  printf("Max value: %d \n",MFKnapsack(n,W));
  return 0;

}

//60,100,120   10,20,30 50