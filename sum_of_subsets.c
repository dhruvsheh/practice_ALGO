#include <stdio.h>
int v[100],w[] = {2, 3, 5, 6, 8, 10}, m = 10,n;
void sos(int s,int k,int r) //k is index of current element
{//s is current sum of the elements in the subset
    //r is remaining sum of elements 
    v[k]=1; 
    if(s+w[k]==m)
    {
        printf("\n");
        for(int i=0;i<n;i++)
        printf("%d\t", v[i]);
    }
    else if(s + w[k] + w[k + 1] <= m)
    sos(s + w[k], k + 1, r - w[k]);
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {//mark the current element as not included(v[k]=0) 
        v[k] = 0;
        sos(s, k + 1,r-w[k]);
    }
}
void main()
{
    n=sizeof(w)/sizeof(w[0]);
    int r=0,i;
    for(i=0;i<n;i++)
    r+=w[i];
    printf("Subsets\n");
    for(i=0;i<n;i++)
    printf("%d\t",w[i]);
    sos(0,0,r);//sos(s,k,r)
}