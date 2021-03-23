
#include <stdio.h>

#define MaxN 500

struct node
{
    // status variables for DFS search
    // visited: already visited? True/False
    // fromm: source node
    int visited, fromm;
    // the adjacency list
    int adj_list[MaxN], *end_of_list;
};

struct node nodes_list[500];
void initialize();
void print_path(int ,int);

int dfs(int);

int n;

int main(){
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    for(int i=0;i<n;i++){
        nodes_list[i].end_of_list = nodes_list[i].adj_list;
    }

    for(int i=0;i<m;i++){
        int friendA, friendB;
        scanf("%d%d",&friendA,&friendB);
        *(nodes_list[friendA].end_of_list++) = friendB;
        *(nodes_list[friendB].end_of_list++) = friendA;
    }

    int k;
    scanf("%d",&k);
    while(k--){
        initialize();
        int start,end;
        scanf("%d%d",&start,&end);
        dfs(start);
        if(nodes_list[end].visited == 0)
            printf("-1\n");
        else
            print_path(end,start);
    }








return 0;
}


//
// utility functions to implement

// DFS explore from the node with index pos
int dfs( int pos ){

    nodes_list[pos].visited = 1;
    int *begin_ptr = nodes_list[pos].adj_list;
    while( begin_ptr != nodes_list[pos].end_of_list){
        if( nodes_list[*begin_ptr].visited == 1){
            begin_ptr++;
            continue;
        }
        nodes_list[*begin_ptr].fromm = pos;
        dfs(*(begin_ptr++) );
    }
    return 0;

}

void initialize(){
    for(int i=0;i<n;i++){
        nodes_list[i].visited = 0;
        nodes_list[i].fromm = 0;
    }
}

// Print the path from s (the source of DFS) to the node p
void print_path( int p, int s ){ //p is initialized by end
    int path_length = 0;
    int record[6002] = {};
    while( p != s){
        record[ path_length++ ] = p;
        p = nodes_list[p].fromm;
    }
    record[ path_length++ ] = p;

    for(int i= path_length-1; i>=0 ; i--){
        printf("%d ",record[i]);
    }
    printf("\n");



return;
}

