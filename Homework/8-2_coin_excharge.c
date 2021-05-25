#include<stdio.h>

// let c1,c2,c3......cn, B(m):用c1~cn組合出m,最少所需硬幣數
//B(m) ={ 0               if m=0
//        min(B(m-ci)+1)  if m>0
//        -1              if m<0}

int coin[100];
int n,m;

void B(int);
int table[20005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);

    scanf("%d",&m);
    B(0);
    printf("%d",table[m]);
return 0;
}

void B(int level){
    if(level == 0){
        table[level] = 0;
        B(level+1);
        return;
    }
    if( level > m)
        return;
    int sol_exist=0;
    int min=-1;//unassigned
    for(int i=0;i<n;i++){
        if( level - coin[i] >= 0 && table[ level-coin[i] ] != -1 ){
            sol_exist = 1;
            if(min == -1)
                min = table[ level-coin[i] ];
            else if(min>table[ level-coin[i] ])
                min = table[ level-coin[i] ];
        }
    }

    if (sol_exist)
        table[level] = min + 1;
    else
        table[level] = -1;
    B(level+1);
}




