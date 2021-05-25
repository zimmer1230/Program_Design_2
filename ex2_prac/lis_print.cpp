#include <stdio.h>
#include <deque>
using namespace std;

int arr[100005];
int dp[100005];
int backward[100005];

void fill_table(int);

int n;
int max_dp=1;
int max_index=0;

int main(){


    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
        backward[i]=-1;
    fill_table(1);
    printf("%d\n",max_dp);
//    for(int i=0;i<n;i++)
//        printf("%d ",backward[i]);

    deque <int> Q;
    Q.push_front( arr[max_index] );
    int pos = max_index;
    while( backward[pos]!=-1 ){
        pos = backward[ pos ];
        Q.push_front( arr[pos] );
    }
    while( !Q.empty() ){
        printf("%d ",Q.front());
        Q.pop_front();
    }




return 0;
}

void fill_table(int level){
    if(level==n)
        return;
    dp[level]=1;
    for(int j=0;j<level;j++){
        if(arr[level]>arr[j]&&dp[level]<dp[j]+1){
            dp[level]=dp[j]+1;
            backward[level]=j;
            if(dp[level]>max_dp){
                max_dp=dp[level];
                max_index=level;
            }
        }
    }
    fill_table(level+1);
}
