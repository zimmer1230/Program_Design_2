#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char name[105];
    int age;
    int weight;
};

int struct_cmp(const struct data *a, const struct data *b){
    if( strcmp( a->name , b->name ) > 0 )
        return 1;
    else if( strcmp( a->name,b->name ) < 0 )
        return -1;
    else if( a->age < b->age )
        return 1;
    else if( a->age > b->age )
        return -1;
    else if ( a->weight < b->weight )
        return 1;
    else
        return 0;
}

int compare(const void *a,const void *b){
    return struct_cmp((struct data*)a,(struct data*)b );

}

int main(){
    int n;
    struct data list[103];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d %d",list[i].name,&list[i].age,&list[i].weight);
    }
    qsort(list,n,sizeof(struct data),compare);
    for(int i=0;i<n;i++){
        printf("%s %d %d\n",list[i].name,list[i].age,list[i].weight);
    }




return 0;
}
