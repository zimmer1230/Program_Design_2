#include <stdio.h>

int arr[10005];
int dp[10005];

void fill_table(int);

int n;
int max_dp=1;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    dp[0]=1;
    fill_table(1);
    printf("%d",max_dp);

return 0;
}

void fill_table(int level){
    if(level==n)
        return;
    dp[level]=1;
    for(int j=0;j<level;j++){
        if(arr[level]>arr[j]&&dp[level]<dp[j]+1){
            dp[level]=dp[j]+1;
            if(dp[level]>max_dp)
                max_dp=dp[level];
        }
    }

    fill_table(level+1);
}
