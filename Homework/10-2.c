#include <stdio.h>

long long arr[100005];
long long sum[100005];
long long best_left[100005];
long long n,value;
int main(){
    scanf("%lld%lld",&n,&value);
    for(long long i=0;i<n;i++){
        if(i==0){
            scanf("%lld",&arr[i]);
            sum[i]=(long long)arr[i];
        }
        else{
            scanf("%lld",&arr[i]);
            sum[i]=(long long)arr[i]+sum[i-1];
        }
    }

    long long left=-2,right;
    for(long long i=0;i<n;i++){
        right=i;
        if(left==-2){
            if(sum[right]>=(long long)value){
                left=0;
            }
        }
        while(right>left){
            if( (sum[right]-sum[left])>=(long long)value ){
                left++;
            }
            else break;
        }
        best_left[i]=left;
    }
    for(long long i=0;i<n;i++)
        printf("%lld ",best_left[i]+1);



return 0;
}
