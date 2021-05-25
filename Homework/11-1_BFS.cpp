#include <stdio.h>
#include <vector>
#include <deque>
using namespace std;

vector <vector<int>> adjacent(500);

int dist[505];
void bfs(int);

int n,t,r;

int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<t;i++){
        int input1,input2;
        scanf("%d%d",&input1,&input2);
        adjacent[input1].push_back(input2);
        adjacent[input2].push_back(input1);
    }
    scanf("%d",&r);
    while(r--){
        for(int i=0;i<n;i++){
            dist[i]=-1;
        }
        int input1,input2;
        scanf("%d%d",&input1,&input2);
        bfs(input1);
        printf("%d\n",dist[input2]);
    }

return 0;
}



void bfs(int p){
    deque<int> QQ;
    dist[p]=0;
    QQ.push_back(p);
    while(!QQ.empty()){
        for(int i=0;i<adjacent[QQ.front()].size();i++)
        if( dist[ adjacent[QQ.front()][i] ]==-1 ){
            QQ.push_back(adjacent[QQ.front()][i]);
            dist[adjacent[QQ.front()][i]]=dist[QQ.front()]+1;
        }
        QQ.pop_front();
    }
}
