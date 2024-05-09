int isSafe(int vertex,int color){
    int i;
    for(i=0;i<n_vertices;i++){
        if(graph[vertex][i]&&colors[i]==color){
            return 0;
        }
    }return 1;
}
int graphcoloring(int vertex){
    if(vertex==n_vertices){
        return1;
    }
    
}