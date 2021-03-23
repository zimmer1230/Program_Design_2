#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return strcmp((char*)a,(char*)b);
}


typedef struct person person;
struct person
{
    char name[21];
    int how_many_friend;
    person *list_of_friends[500]; // friend list
    //person **end_of_list; // pointer to the end of friend list
};

person* find_friend(person [],int,char []);

int main(){
    person list[500];
    int people;
    scanf("%d",&people);
    for(int i=0;i<people;i++){
        scanf("%s",list[i].name);

    }
    qsort(list,people,sizeof(person), compare);


    int command;
    scanf("%d",&command);
    while(command--){
        char tmp[40];
        scanf("%s",tmp);
        char NameA[20],NameB[20];
        if(!strcmp(tmp,"MakeFriend")){
            scanf("%s%s",NameA,NameB);
            person *A_pos,*B_pos;
            A_pos = find_friend(list,people,NameA);
//            printf("A is %s\n",A_pos->name);
            B_pos = find_friend(list,people,NameB);
//            printf("B is %s\n",B_pos->name);
            A_pos->list_of_friends[ A_pos->how_many_friend++ ] = B_pos;
            B_pos->list_of_friends[ B_pos->how_many_friend++ ] = A_pos;
        }
        else if(!strcmp(tmp,"ListFriend")){
            scanf("%s",NameA);
            person* A_pos;
            A_pos = find_friend(list,people,NameA);
            for(int t=0;t< A_pos->how_many_friend;t++)
                printf("%s ", A_pos->list_of_friends[t]);
            printf("\n");

        }
    }



return 0;
}


person* find_friend(person list[],int length, char target[]){
    int left = -1, right = length, mid;
    while ( left < right - 1){
        mid = (left + right)/2;
        if ( strcmp ( list[mid].name , target) < 0)
            left = mid;
        else
            right = mid;
    }
    return &list[right];

}
