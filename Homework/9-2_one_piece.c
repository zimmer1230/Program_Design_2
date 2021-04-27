#include <stdio.h>

int wind[100005];
int circle;
int target;

int effect[100005];
void calculate_effect();

int is_arrived(long long);

int main(){

    scanf("%d",&circle);
    char kaze[100005];
    scanf("%s",kaze);
    for(int i=0;i<circle;i++){
        if(kaze[i]=='W')
            wind[i]=-1;
        else
            wind[i]=1;
    }

    calculate_effect();

    scanf("%d",&target);



    long long left=(target%2)?( (target+1)/2 )-(long long)1:(target/2)-(long long)1;
    long long right=(target%2)?(long long)circle*((target+1)/2)+1:(long long)circle*(target/2)+1;
    long long max_day=right-1;
    //fast=target/2, latest=target/2*circle || x
    long long mid=(left+right)/2;
    while(right-left>1){
        if( is_arrived(mid) )
            right = mid;
        else
            left = mid;
        mid = (left+right)/2;
    }
    if(right>max_day)
        printf("-1");
    else
        printf("%lld",right);









return 0;
}

void calculate_effect(){
    effect[0]=wind[0];
    for(int i=1;i<circle;i++)
        effect[i]=effect[i-1]+wind[i];
}
int is_arrived(long long day){ //WEE
    long long pos;
    if(day%circle==0)
        pos= day + (day/circle)*effect[circle-1];
    else
        pos= day + (day/circle)*effect[circle-1] + effect[day%circle-1];

    if(pos>=(long long)target)
        return 1;
    else
        return 0;
}
