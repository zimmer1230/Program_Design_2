#include <stdio.h>

int coin[1000];
int dp[20005];

void fill_dp();

int n,m;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }
    scanf("%d",&m);
    fill_dp();
    printf("%d",dp[m]);

return 0;
}

void fill_dp(){
    dp[0]=0;
    for(int k=1;k<m+1;k++){
         int min=-1;
         for(int i=0;i<n;i++){
            if( k-coin[i]>=0 && dp[ k-coin[i] ]!=-1 ){
                if(min==-1) min=dp[ k-coin[i] ]+1;
                else if(min>dp[ k-coin[i] ]+1) min=dp[ k-coin[i] ]+1;
            }
         }
         dp[k]=min;
    }
}
