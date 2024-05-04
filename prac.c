int place(int d){
    int j;
    for(j=1;j<d;j++){
        if(a[j]==a[d]||abs(a[j]-a[d]==abs(j-d))){
            return 0;
        }
    }
    return 1;
}

void QUEEN(int n){
    int k=1;
    a[k]=0;
    while(k!=0){
        do{

        a[k]++;
            }while(k<=n&&!place(k));
    

    }
    

}