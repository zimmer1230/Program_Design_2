#include <stdio.h>
#include <string.h>

typedef struct person person;
struct person
{
    char name[21];
    int how_many_friend;
    person *list_of_friends[500]; // friend list
    person **end_of_list; // pointer to the end of friend list
};

int main(){
    person list[500];
    int people;
    scanf("%d",&people);
    for(int i=0;i<people;i++){
        scanf("%s",list[i].name);

    }
    int command;
    scanf("%d",&command);
    while(command--){
        char tmp[40];
        scanf("%s",tmp);
        char NameA[20],NameB[20];
        if(!strcmp(tmp,"MakeFriend")){
            scanf("%s%s",NameA,NameB);
            int A_pos,B_pos;
            for(int i=0;i<people;i++){
                if( !strcmp(list[i].name,NameA) )
                    A_pos=i;
                if( !strcmp(list[i].name,NameB) )
                    B_pos=i;
            }
            list[A_pos].list_of_friends[ list[A_pos].how_many_friend++ ] = &list[B_pos];
            list[B_pos].list_of_friends[ list[B_pos].how_many_friend++ ] = &list[A_pos];
        }
        else if(!strcmp(tmp,"ListFriend")){
            scanf("%s",NameA);
            int A_pos;
            for(int i=0;i<people;i++){
                if( !strcmp(list[i].name,NameA) ){
                    A_pos=i;
                    break;
                }
            }
            for(int t=0;t<list[A_pos].how_many_friend;t++)
                printf("%s ",list[A_pos].list_of_friends[t]);
            printf("\n");

        }
    }




return 0;
}
