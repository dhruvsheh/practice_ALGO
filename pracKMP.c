void prefix_table(char pat[],int m,int LPS[]){
    int x=0;
    int y=1;
    LPS[0]=0;
    while(y<m){
        if(pat[x]==pat[y]){
            x++;
            LPS[y]=x;
            y++;
        }
        else{
            if(x!=0){
                x=LPS[x-1];
            }
            else{
                LPS[y]=0;
                y++;
            }
        }
    }
}
void search(char txt[],char pat[]){
   int m=strlen(pat);
   int n=strlen(txt);
   int LPS[20];
   prefix_table(pat,m,LPS);
   int i=0;
   int j=0;
   while(i<n){
    if(txt[i]==pat[j]){
        i++;
        j++;
    }
    if(j==m){
        printf("pattern found at index %d",i-j);
    }
    else if(i<n&&txt[i]!=pat[j]){
        j=LPS[j-1];
    }
    if

    }
   }

