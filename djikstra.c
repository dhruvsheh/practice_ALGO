#include<stdio.h>
#include<conio.h>
int n,source,V[20],parent[20],dist[20],i,j,k; //V[20] to show if a vertex has been visited or not yet
int graph[6][6]={{0, 4, 0, 0, 0, 0},
                {4, 0, 8, 0, 0, 0},
                {0, 8, 0, 7, 0, 4},
                {0, 0, 7, 0, 9, 14},
                {0, 0, 0, 9, 0, 10},
                {0, 0, 4, 14, 10, 0}};
void initialise_single_source(){
    for(i=0;i<n;i++){
        dist[i]=10000;
        parent[i]=-1;
    }
    dist[source]=0;
}
int find_minimum(){                                      
    int min = 1000;
    int temp = -1;
    for(i=0;i<n;i++){
        if(dist[i]<min && V[i] == 0){
            temp = i;
            min = dist[i];
        }
    }
    V[temp] = 1;
    return temp;
}
void relax(int u,int v){
    if(dist[v]>dist[u]+graph[u][v]){
        dist[v]=dist[u]+graph[u][v]
        parent[v]=u;
    }
}

void djikstra(){
    initialise_single_source();
    for(i=0;i<n;i++){
        int u=find_minimum();
        for(j=0;j<n;j++){ //VIMP PART,GRAPH[U][J] WHERE U IS FIND_MIN() KA ANSWER 
            if(graph[u][j]!=0&&V[j]==0){  //if weight is not 0 and vertex not visited
                relax(u,j);
            }
        }
    }
}
void display(){
    
}
