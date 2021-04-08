#include <stdio.h>
#include<algorithm>
using namespace std;

int result[100005];
void record_result(int,int);

int result_min[2][100005];
void find_result_min(int);

int arr[100005];
int n;


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    record_result(0,n-1);
    find_result_min(0);
//    for(int i=0;i<n;i++){
//        printf("%d ",result_min[0][i]);
//    }
//    printf("\n");
//    for(int i=0;i<n;i++){
//        printf("%d ",result_min[1][i]);
//    }
//    printf("\n");

    struct anser_format{
        int value;
        int left;
        int right;
    }ans;
    ans.value = result[0];
    ans.left=0;
    ans.right=0;


    for(int i=1;i<n;i++){
//        printf("ans value is %d\n",ans.value);
        if (ans.value < result[i] - result_min[0][i-1] ){
            ans.value = result[i] - result_min[0][i-1];
            ans.left  = result_min[1][i-1]+1;
            ans.right = i;
        }
    }
    printf("%d %d\n%d",ans.left+1,ans.right+1,ans.value);






return 0;
}

void record_result(int left,int right){
    if(left==n) return;
    if(left==0){
        result[left]=arr[0];
    }
    else {
    result[left]=result[left-1]+arr[left];
    }
    record_result(left+1,right);
}

void find_result_min(int level){
    if(level==n) return;
    if(level==0&&result[0]<0) {
            result_min[0][0]=result[0];
            result_min[1][0]=0;
    }
    else{
        if(result_min[0][level-1]>result[level]){
            result_min[0][level]=result[level];
            result_min[1][level]=level;
        }
        else{
            result_min[0][level]=result_min[0][level-1];
            result_min[1][level]=result_min[1][level-1];

        }
    }
    find_result_min(level+1);
}


