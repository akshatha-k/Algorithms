#include<stdio.h>
 
#define MAX 30
 
typedef struct edge
{
	int u,v,w;
}edge;
 
typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;
 
edgelist elist;
 
int adj[MAX][MAX],n;
edgelist minspan;

 
int find(int order[],int vertexno)
{
	return(order[vertexno]);
}
 
void union1(int order[],int c1,int c2)
{
	int i;	
	for(i=0;i<n;i++)
		if(order[i]==c2)
			order[i]=c1;
}
 
void sort()
{
	int i,j;
	edge temp;	
	for(i=1;i<elist.n;i++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}
 
void print()
{
	int i,cost=0;
	for(i=0;i<minspan.n;i++)
	{
		printf("\n%c\t%c\t%d",'a'+minspan.data[i].v,'a'+minspan.data[i].u,minspan.data[i].w);
		cost=cost+minspan.data[i].w;
	}
	printf("\n\nCost of the spanning tree=%d",cost);
}
void kruskal()
{
	int order[MAX],i,j,cno1,cno2;
	elist.n=0;
 
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(adj[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=adj[i][j];
				elist.n++;
			}
		}
 
	sort();
	
	for(i=0;i<n;i++)
		order[i]=i;
	
	minspan.n=0;
	
	for(i=0;i<elist.n;i++)
	{
		cno1=find(order,elist.data[i].u);
		cno2=find(order,elist.data[i].v);
		
		if(cno1!=cno2)
		{
			minspan.data[minspan.n]=elist.data[i];
			minspan.n=minspan.n+1;
			union1(order,cno1,cno2);
		}
	}
}
void main()
{
	int i,j,total_cost;
	printf("\nEnter number of vertices:");	
	scanf("%d",&n);	
	printf("\nEnter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&adj[i][j]);		
	kruskal();
	print();
}
