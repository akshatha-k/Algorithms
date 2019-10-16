/* Dijkstra's Algorithm in C */
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define IN 99

int dijsktra(int cost[][20],int source,int target,int N)
{
    int i,m,min,start,d,j;
    int *dist=(int*)malloc(sizeof(int)*N);
    int *prev=(int*)malloc(sizeof(int)*N);
    int *selected=(int*)malloc(sizeof(int)*N);
    char *path=(char*)malloc(sizeof(char)*N);
    char *revpath=(char*)malloc(sizeof(char)*N);
    for(i=1;i< N;i++)
    {
        dist[i] = IN;
        prev[i] = -1;
    }
    start = source;
    selected[start]=1;
    dist[start] = 0;
    while(selected[target] ==0)
    {
        min = IN;
        m = 0;
        for(i=1;i< N;i++)
        {
            d = dist[start] +cost[start][i];
            if(d< dist[i]&&selected[i]==0)
            {
                dist[i] = d;
                prev[i] = start;
            }
            if(min>dist[i] && selected[i]==0)
            {
                min = dist[i];
                m = i;
            }
        }
        start = m;
        selected[start] = 1;
    }
    start = target;
    j = 0;
    while(start != -1)
    {
        path[j++] = start+65-1;
        start = prev[start];
    }
    path[j]='\0';
    for(i=0;i<j;i++)
    {
        revpath[i]=path[j-i-1];
    }
    printf("%s", revpath);
    return dist[target];
}
int main()
{
    int cost[20][20],i,j,w,ch,co,N;
    int source, target,x,y;
    printf("\t Enter number of vertices \n\n");
    scanf("%d",&N);
    N+=1;
    for(i=1;i< N;i++)
    for(j=1;j< N;j++)
    cost[i][j] = IN;
    for(x=1;x< N;x++)
    {
        for(y=x+1;y< N;y++)
        {
            printf("Enter the weight of the path between nodes %d and %d: ",x,y);
            scanf("%d",&w);
            cost [x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    printf("\nEnter the source:");
    scanf("%d", &source);
    for(i=1; i<N;i++)
    {
        if(source!=i)
        {
            co = dijsktra(cost,source,i,N);
            printf("\nThe Shortest Path: %d \n",co);
        }

    }
}
