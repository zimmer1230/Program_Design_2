#include <stdio.h>


int weight_limit;
int value_weight[2000][2];

void opt(int);
int table[2000][2000];
int t;

int main(){
    scanf("%d%d",&t,&weight_limit);
    for(int i=0;i<t;i++){
        scanf("%d%d",&value_weight[i][0],&value_weight[i][1]);//0:value,1:weight
    }
    for(int j=0;j<=weight_limit;j++){
        table[0][j]=(j-value_weight[0][1]<0)?0:value_weight[0][0];
    }
    opt(1);
    printf("%d",table[t][weight_limit]);
return 0;
}

int max(int a,int b,int c){
    int m=(a>=b)?a:b;
return (m>=c)?m:c;
}

int is_overwhelm(int i,int w){
    if(w-value_weight[i][1]<0)
        return -1;
    return table[i-1][ w-value_weight[i][1] ]+value_weight[i][0];
}

void opt(int i){
    if(i>t) return;
    for(int j=1;j<=weight_limit;j++){ //wj
        int max_val=max(table[i-1][j],is_overwhelm(i,j),table[i][j-1]);
        table[i][j]=max_val;
    }
    opt(i+1);
}
