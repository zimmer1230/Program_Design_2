#include<stdio.h>

int number_set[2000];
int n;

int A(int,int);
int combility[2000][2000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&number_set[i]);

    int k;
    scanf("%d",&k);
    A(0,k);
    if()
        printf("Yes\n");
    else
        printf("No\n");




return 0;
}


int A(int i,int k){ // determine if the combination k exists before i


}
