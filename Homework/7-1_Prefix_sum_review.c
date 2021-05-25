#include <stdio.h>

int arr[1000005];
int prefix_sum[100005];
int n,t;

int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(i==0){
            prefix_sum[i]=arr[i];
        }
        else{
            prefix_sum[i]=prefix_sum[i-1]+arr[i];
        }
    }
    while(t--){
        int input_1,input_2;
        scanf("%d%d",&input_1,&input_2);
        if(input_1>1)
        printf("%d\n",prefix_sum[input_2-1]-prefix_sum[input_1-2]);
        else
        printf("%d\n",prefix_sum[input_2-1]);
    }



return 0;
}
