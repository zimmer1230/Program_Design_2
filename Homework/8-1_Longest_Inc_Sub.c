#include <stdio.h>

int table[10005]; // table[i] is defined that the LIS ending in arr[i]

int main(){
    int n;
    int arr[10005]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int table_max=1;
    table[0]=1;

    for(int i=1;i<n;i++){
        int smaller_index = -1;
        int smaller_max = 0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(smaller_max<table[j]){
                    smaller_max = table[j];
                    smaller_index = j;
                }
            }
        }
        if( smaller_index == -1)
            table[i] = 1;
        else
            table[i] = table[smaller_index]+1;
        if(table_max<table[i])
            table_max = table[i];
    }
    printf("%d",table_max);






}

