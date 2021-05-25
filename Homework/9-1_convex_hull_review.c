#include <stdio.h>

int points[10005][2];
int *wrap_order[10005];

int n;

int main(){

    scanf("%d",&n);
    int *start_point;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&points[i][j]);  //i-th point
            if(i==0) start_point=points[i];
            else if( *(start_point)<=points[i][0] ){
                if( *(start_point)<points[i][0] )
                    start_point=points[i];
                else if(*(start_point+1)<points[i][1])
                    start_point=points[i];
            }
        }
    }
    wrap_order[0]=start_point;









return 0;
}
