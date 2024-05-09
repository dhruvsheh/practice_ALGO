#include<stdio.h>
#include<string.h>

void computeLPS(char pat[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPSearch(char txt[], char pat[]){
    int m = strlen(pat);
    int n = strlen(txt);
    int lps[20];
    computeLPS(pat,m,lps);
        int i =0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            printf("pattern found at index: %d\n", i-j);
            j = lps[j-1];
        }
        else if(i<n && txt[i]!=pat[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j!=m){
        printf("no more patterns");
    }
}
void main(){
    char txt[] = {"ABABDABACDABABCABAB"};
    char pat[] = {"ABAB"};
    KMPSearch(txt, pat);
}