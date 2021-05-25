#include <stdio.h>

int f(int x){
    if(x==0) return 1;
    if( x%10==0 ) return 1*f( x/10 );
    return x%10*f(x/10);
}


int f_result[1000006];

int g(int x){
    if(x<10) return x;
    return g( f_result[x] );
}
int g_result[1000006];

int k_table[10][1000006]; //k_table[3][67] means that int range 1~67, k=3 has k_table[3][67] elements

int query;
int main(){

    for(int i=1;i<1000001;i++){
        f_result[i]=f(i);
    }

    for(int i=1;i<1000001;i++){
        g_result[i]=g(i);
        for(int j=1;j<10;j++){
            k_table[j][i]=k_table[j][i-1];
        }
        if( g_result[i] <10 ){
//            printf("i==%d,g(i)==%d\n",i,g_result[i]);
            k_table[ g_result[i] ][i]++;
        }
    }

    scanf("%d",&query);
    int left,right,k;
    while(query--){
        scanf("%d%d%d",&left,&right,&k);
        printf("%d\n",k_table[k][right]-k_table[k][left-1]);
    }



return 0;
}
