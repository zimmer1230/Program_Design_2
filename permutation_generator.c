#include <stdio.h>

void permutation_generator(int);
int n=-1;
int permutation[100];
int mark[100];

int main(){
    permutation_generator(3);
    return 0;
}

void permutation_generator(int level){
    if(n==-1){
        n=level;
        level = 1;
    }
    if(level>n){
        for(int i=1;i<=n;i++){
            printf("%d ",permutation[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++){
        if(mark[i]==0){
            mark[i]=1;
            permutation[level]=i;
            permutation_generator(level+1);
            mark[i]=0;
        }
    }


}
