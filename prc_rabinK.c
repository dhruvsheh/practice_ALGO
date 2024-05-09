#include<stdio.h>
#include<string.h>
#include<math.h>
#define d 256
char pat[100],txt[100];
int h=1;
int q;
int p=0;
int t=0;
void search(char pat[],char txt[],int q){
    int M=strlen(pat);
    int N=strlen(txt);
    int i,j;
    for(i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    for(i=0;i<M;i++){
        p=(d*p+pat[i])%q;
        q=(d*q + txt[i])%q;
    }
    for(i=0;i<=N-M;i++){
        if(p==t){
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==M){
                    printf("patter found from index %d to index %d",i,i+M);
        }
            if(i<N-M){

            }

        }
        
    }


}