#include<stdio.h>
int start[50]={1,3,0,5,3,5,6,7,8,2,12},end[50]={4,5,6,7,9,9,10,11,12,14,16},n=11;
void sort(){
    int tempS=0,tempE=0,i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(end[j]>end[j+1]){
                tempE=end[j];
                end[j]=end[j+1];
                end[j+1]=tempE;
                tempS=start[j];
                start[j]=start[j+1];
                start[j+1]=tempS;
            }
        }
    }

}
void ActivitySelection(){
    int i,count=0,selected=0;
    for(i=0;i<n;i++){
        if(start[i]>=selected){
            printf("take from %d to %d",start[i],end[i]);
            selected=end[i];
            count++;
        }
    }
}

