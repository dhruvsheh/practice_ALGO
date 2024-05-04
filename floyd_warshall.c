#include <stdio.h>
#define v 4
#define INF 99999

void floydWarshall(int d[v][v]){//as it is an even matrix
    int i,j,k;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            for(k=0;k<v;k++){
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j]
                }
            }
        }
    }
    printf("all pair shortest paths are:");
    for (i = 0; i < v; i++){
        for (j = 0; j < v; j++){
            if (d[i][j] == INF)
                printf("%s ", "INF");
            else
                printf("%d ", d[i][j]);
        }
    }
}
