#include <stdio.h>
#include <vector>
using namespace std;

int matrix[500][500];
int n,m;

vector <vector<int>> added_record(500);
vector <int> m_added_record(500);

int is_zero(int i){
    for(int k=0;k<n;k++){
        if(matrix[i][k])
            return 0; // isn't zero
    }
    return 1;
}
void add_to(int i, int j){
    for(int k=0;k<n;k++){
        matrix[j][k] = matrix[j][k] ^ matrix[i][k];
    }
}

int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        added_record[i].push_back(i);
    }

    int matrix_dim=0;
    for(int i=0;i<m;i++){
        if(is_zero(i)){
            continue;
        }
        matrix_dim++;
        for(int j=i+1;j<m;j++){
                for(int k=0;k<n;k++){
                    if(matrix[i][k]){
                        if(matrix[i][k]&&matrix[j][k]){
                            for(int x=0;x<added_record[i].size();x++)
                                added_record[j].push_back(added_record[i][x]);
                            add_to(i,j);
                            break;
                        }
                        else break;
                    }

                }
        }
    }

//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            printf("%d ",matrix[i][j]);
//        }
//        printf("\n");
//    }



    int time;
    scanf("%d",&time);
    while(time--){
        m_added_record.clear();
        for(int j=0;j<n;j++)
            scanf("%d",&matrix[m][j]);


        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                if(matrix[i][k]){
                    if(matrix[i][k]&&matrix[m][k]){
                        add_to(i,m);
                        for(int j=0;j<added_record[i].size();j++)
                            m_added_record.push_back(added_record[i][j]);
                        break;
                    }
                    else break;
                }
            }
        }

        if(is_zero(m)){
            int printing_ans[500]={};
            for(int i=0;i<m_added_record.size();i++){
                printing_ans[ m_added_record[i] ]++;
            }
            for(int i=0;i<n;i++){

                if(printing_ans[i]%2) printf("%d ",i);
            }
            printf("\n");

        }
        else
            printf("-1\n");

    }



return 0;
}

