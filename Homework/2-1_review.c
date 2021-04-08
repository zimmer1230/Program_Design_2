#include <stdio.h>

struct node{
    int visited;
    int fromm;
    int adj[500];
    int adj_n;
}nodes_list[500];

void explore_social_network(int);
void initialize();

void print_path(int ,int);

int n,m;
int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int friend_a,friend_b;
        scanf("%d%d",&friend_a,&friend_b);
        nodes_list[friend_a].adj[ nodes_list[friend_a].adj_n++ ] = friend_b;
        nodes_list[friend_b].adj[ nodes_list[friend_b].adj_n++ ] = friend_a;
    }

    int k;
    scanf("%d",&k);

    while(k--){
        initialize();
        int start,end;
        scanf("%d%d",&start,&end);
        explore_social_network(start);
        nodes_list[end].visited ? printf("Yes\n") : printf("No\n");
        print_path(start,end);

    }



return 0;
}



void explore_social_network(int pos){
    if(nodes_list[pos].visited==1) return;
    nodes_list[pos].visited=1;
    for(int i=0;i<nodes_list[pos].adj_n;i++){
        nodes_list[ nodes_list[pos].adj[i] ].fromm = pos;
        explore_social_network(nodes_list[pos].adj[i]);
    }


}
void initialize(){
    for(int i=0;i<n;i++)
        nodes_list[i].visited = 0;
}

void print_path(int start,int end){
    int path[500];
    int path_n;

    while(start)



}


