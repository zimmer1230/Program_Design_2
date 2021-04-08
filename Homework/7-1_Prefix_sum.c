#include <stdio.h>

int result[100005];
void record_result(int,int);

int arr[100005];
int n;

int main(){
    int t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    record_result(n-1,n-1);



    while(t--){
        int left,right;
        scanf("%d%d",&left,&right);
        left--,right--;
        if(right!=n-1)
            printf("%d\n",result[left]-result[right+1]);
        else
            printf("%d\n",result[left]);
    }
return 0;
}

void record_result(int left,int right){
    if(left<0) return;
    if(left==n-1){
        result[left]=arr[n-1];
        record_result(left-1,right);
    }

    result[left]=result[left+1]+arr[left];
    record_result(left-1,right);


}
