#include<stdio.h>
#define MAX 100
int n_vertices, n_edges, n_colors;
int colors[MAX];
int graph[MAX][MAX];
int isSafe(int vertex,int color)
{
    for(int i=0;i<n_vertices;i++)
    {
        if(graph[vertex][i] && colors[i]==color)//This checks if the color assigned to vertex i is the same as the color we want to assign to the current vertex
        return 0;
    }
    return 1;
}
int graphColoring(int vertex)
{
    if(vertex==n_vertices)
    return 1;
    for(int i=1;i<=n_colors;i++)
    {
        if(isSafe(vertex,i)==1)
        {
            colors[vertex]=i;
            if(graphColoring(vertex+1))
            return 1;
            else
            colors[vertex]=0;
        }
    }
    return 0;
}
void main()
{
    printf("Enter the number of vertices : ");
    scanf("%d",&n_vertices);
    printf("Enter the number of edges : ");
    scanf("%d",&n_edges);
    printf("Enter the number of colors : ");
    scanf("%d",&n_colors);
    int i, j;
    for(i=0;i<n_vertices;i++)
    {
        colors[i]=0;  //initialize all edges w weight 0 and no color
        for(j=0;j<n_vertices;j++)
        graph[i][j] = 0;
    }
    for (i=0; i<n_edges; i++) {
        int u, v;
        printf("Enter the edge %d : ", i+1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    if(graphColoring(0)==1)
    {
        printf("Vertices \t Colors\n");
        for (i=0; i<n_vertices; i++) 
        printf("Vertex %d : \t\t%d \n", i, colors[i]);
    }
    else
    printf("Cannot be done with %d colors",n_colors);
} 