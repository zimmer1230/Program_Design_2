#include <stdio.h>

int arr[100005];
int prefix_sum[100005];
int prefix_sum_min[2][100005];
int n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i==0){
            prefix_sum[i]=arr[i];
            if(prefix_sum[i]<0){
                prefix_sum_min[0][i]=prefix_sum[i];
                prefix_sum_min[1][i]=i;
            }
        }
        else{
            prefix_sum[i]=prefix_sum[i-1]+arr[i];
            if(prefix_sum[i]<prefix_sum_min[0][i-1]){
                prefix_sum_min[0][i]=prefix_sum[i];
                prefix_sum_min[1][i]=i;
            }
            else{
                prefix_sum_min[0][i]=prefix_sum_min[0][i-1];
                prefix_sum_min[1][i]=prefix_sum_min[1][i-1];
            }
        }
    }

    int max=prefix_sum[0];
    int left=0,right=0;
    for(int i=1;i<n;i++){
        if(max<prefix_sum[i]-prefix_sum_min[0][i-1]){
            max=prefix_sum[i]-prefix_sum_min[0][i-1];
            left=prefix_sum_min[1][i-1];
            right=i;
        }
    }
//    for(int i=0;i<n;i++){
//        printf("%d %d\n",prefix_sum_min[0][i],prefix_sum_min[1][i]);
//    }
    if(left==right){
        printf("%d %d\n%d",left+1,left+1,max);
    }
    else{
        printf("%d %d\n%d",left+2,right+1,max);
    }








return 0;
}

