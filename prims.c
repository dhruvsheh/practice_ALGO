#include<stdio.h>
int dist[20], par[20], v[20], n, s;
int g[6][6] = {{0, 4, 0, 0, 0, 0},
            {4, 0, 8, 0, 0, 0},
            {0, 8, 0, 7, 0, 4},
            {0, 0, 7, 0, 9, 14},  //this is an Adjacency list,of size 6,so vertices are 0,1..5
            {0, 0, 0, 9, 0, 10},  //0th index shows vertex 0 is connected to which vertices and the weights of their edges
            {0, 0, 4, 14, 10, 0}};

void initialise_single_source(){
    for(int i=0;i<n;i++){
        dist[i] = 10000;
        par[i]=-1;  //parent of all vertices as null
        // v[i]=0;
    }
    dist[s]=0;
}
int find_min(){
    int min = 1000;
    int temp = -1;
    for(int i=0;i<n;i++){
        if(dist[i]<min && v[i]==0){
            temp = i;
            min = dist[i];
        }
    }
    v[temp]=1;
    return temp;
}
void relax(int u,int v){
    if(dist[v]>g[u][v]){
        dist[v]=g[u][v];
        par[v]=u;
    }
}
void display(){
    int sum = 0;
    printf("dist\tpar\n");  
    for(int i=0;i<n;i++){
        printf("%d\t%d\n",dist[i],par[i]);  //to make the table of distance and parents
        sum = sum + dist[i];
    }
    printf("total cost of MST: %d",sum);
}
void prim(){
    initialise_single_source();
    for(int i=0;i<n;i++){
        int u = find_min();
        for(int j=0;j<n;j++){
            if(g[u][j]!=0 && v[j]==0){
                relax(u,j);
            }
        }
    }
    display();
}
void main(){
    n=6;
    printf("Graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("Enter starting point: ");
    scanf("%d",&s);
    prim();
}