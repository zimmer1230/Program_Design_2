#include <stdio.h>

int value_weight[1005][2];

int dp[1005][1005];
void fill_dp();


int n,weight_limit;
int main(){

    scanf("%d%d",&n,&weight_limit);
    for(int i=0;i<n;i++){
        scanf("%d%d",&value_weight[i][0],&value_weight[i][1]);//0:value,1:weight
    }
    fill_dp();
//    for(int i=0;i<n;i++){
//        for(int w=0;w<=weight_limit;w++){
//            printf("%d ",dp[i][w]);
//        }
//        printf("\n");
//    }
    printf("%d",dp[n-1][weight_limit]);


return 0;
}

int max(int a,int b){
if(a>b) return a;
else return b;
}

void fill_dp(){
    for(int j=0;j<=weight_limit;j++){
        dp[0][j]=(j-value_weight[0][1]<0)?0:value_weight[0][0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=weight_limit;j++){
            if(j-value_weight[i][1]<0){
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j]=max(dp[i-1][j],dp[i-1][ j-value_weight[i][1] ]+value_weight[i][0]);
        }
    }
}
