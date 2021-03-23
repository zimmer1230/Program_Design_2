
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
            printf("No\n");
        else
            printf("Yes\n");
    }








return 0;
}


//
// utility functions to implement

// DFS explore from the node with index pos
int dfs( int pos ){
    if(nodes_list[pos].visited == 1)
        return 0;
    nodes_list[pos].visited = 1;
    int *begin_ptr = nodes_list[pos].adj_list;
    while( begin_ptr != nodes_list[pos].end_of_list){
        nodes_list[*begin_ptr].fromm = pos;
        dfs(*begin_ptr++);
    }
    return 0;

}

void initialize(){
    for(int i=0;i<n;i++){
        nodes_list[i].visited = 0;
    }


}

// Print the path from s (the source of DFS) to the node p
void print_path( int p, int s );
