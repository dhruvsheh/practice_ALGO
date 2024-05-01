#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[30],count=0;
int place(int r)
{
    int j;
    for(j=1;j<r;j++)
    {
        if(a[j]==a[r]|| abs(a[j]-a[r])== abs(j-r))  //no same columns or in diagonal to each other
        return 0;
    }       
    
    return 1;
}
void print_sol(int n)
{
    int i,j;
    count++;
    printf("solution %d\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==j) //If a[i] equals j,
                        //it means there is a queen placed in row i at column j.
            {
                printf("Q\t");
            }
            else
            printf("*\t");
        }
        printf("\n");
    }
}
void queen(int n)
{
    int k=1;
    a[k]=0;  //This indicates that initially, no queen has been placed in the first row.
    while(k!=0)
    {
        do{
            a[k]++;
        }while(a[k]<=n && !place(k));  //either a[k] exceeds the size of the chessboard n 
                                       //or until the place function returns false
                                       //(indicating that placing a queen at position a[k] in row k is not valid)
        if(a[k]<=n)
        {
            if(k==n)
            {
                print_sol(n);
            }
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
        k--;
    }
}
void main()
{
    int n;
    printf("Enter no of queens:");
    scanf("%d",&n);
    queen(n);
    printf("Total Solutions: %d",count);
}