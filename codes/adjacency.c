#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int adj[MAX][MAX];

struct node
{
    int vertex;
    struct node* next;
};
struct Graph
{
    int numVertices;
    struct node** adjLists;
};
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch, n, max_edges,i, j,origin=0, destin=0;
    int graph_type;
    printf("Enter 1 for adjacency list \n");
    printf(" Enter 2 for adjacency matrix \n");
    scanf("%d",&ch);
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    printf("Enter type of graph, 1 for directed , 2 for undirected (d/u) : \n");
    scanf("%d",&graph_type);
    if(graph_type==2)
    {
  		max_edges=n*(n-1)/2;
    }
  	else
    {
  		max_edges=n*(n-1);
    }
    struct Graph* graph = createGraph(n);
      for(i=1;i<=max_edges;i++)
    	{
        printf("Enter edge ( 0 0 to quit ) : \n");
    		scanf("%d %d",&origin,&destin);
    		if( (origin==0) && (destin==0) )
    			break;
    		if( origin >= n || destin >= n || origin<0 || destin<0)
    		{
    			printf("Invalid edge!\n");
          exit(0);
    			i--;
    		}
        else
        {
          if(ch==1)
          {
            addEdge(graph, origin, destin);
          }
          else if(ch==2)
          {
            adj[origin][destin]=1;
      			if( graph_type==2)
      				adj[destin][origin]=1;
          }
        }


    	}

    if (ch==1)
      printGraph(graph);
    else
    {
      printf("The adjacency matrix is :\n");
    	for(i=0;i<n;i++)
    	{
    		for(j=0;j<n;j++)
    			printf("%4d",adj[i][j]);
    		printf("\n");
    	}
    }

    return 0;
}
