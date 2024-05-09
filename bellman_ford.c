#include<stdio.h>

int graph[8][8]={
    {0,6,5,5,0,0,0},
    {0,0,0,0,-1,0,0},
    {0,-2,0,0,1,0,0},
    {0,0,-2,0,0,-1,0},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0},
};

int n=7;
int dist[50],parent[50],source=0,c=0;

void initialize_Single_Source()
{
    for(int i=0;i<n;i++)
    {
        dist[i]=99999;
        parent[i]=-1;
    }
    dist[source]=0;
}

void relax(int u,int v)
{
    if(dist[v]>dist[u]+graph[u][v])
    {
        dist[v]=dist[u]+graph[u][v];
        parent[v]=u;
    }
}

void BellmanFord()
{
    initialize_Single_Source();

    for(int k=0;k<n;k++)  //relax all edges
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]!=0)  //doesnot matter if visited or not.
                {
                    relax(i,j);
                }
            }
        }
    }

    // Check for negative cycles
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[j]>dist[i]+graph[i][j] && graph[i][j]!=0)
            {
                c=1;
                return; // //means even after using relax function d[v]>d[u]+graph[u][v],so NEGATIVE CYCLE DETECTED
            }
        }
    }
}

int main()
{
    BellmanFord();  
    if(c==1)
    {
        printf("no answer\n");
    }
    else
    {
        printf("Distance :");
        for(int i=0;i<n;i++)
        {
            printf("%d ",dist[i]);
        }
        printf("\n");
        printf("parent:");
        for(int i=0;i<n;i++)
        {
            printf("%d ",parent[i]+1);
        }
        printf("\n");
    }
    return 0;
}
