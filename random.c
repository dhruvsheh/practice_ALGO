for(i=0;i<n;i++){
    int u=find_mini();
    for(j=0;j<n;j++){
        if(graph[u][j]!=0&&V[j]==0){
            relax(u,j);
        }

    }
}