#include <stdio.h>

int matrix[500][500];
int n,m;
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

    int matrix_dim=0;
    for(int i=0;i<m;i++){
        if(is_zero(i))
            continue;
        matrix_dim++;
        for(int j=i+1;j<m;j++){
                for(int k=0;k<n;k++){
                    if(matrix[i][k]&&matrix[j][k])
                        add_to(i,j);
                }
        }
    }
    int time;
    scanf("%d",&time);
    while(time--){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[m][j]);
        }
        int new_matrix_dim = 0;
        for(int i=0;i<m+1;i++){
            if(is_zero(i))
                continue;
            new_matrix_dim++;
            for(int j=i+1;j<m+1;j++){
                    for(int k=0;k<n;k++){
                        if(matrix[i][k]&&matrix[j][k])
                            add_to(i,j);
                    }
            }
        }

        if(new_matrix_dim == matrix_dim )
            printf("Yes\n");
        else
            printf("No\n");

    }



return 0;
}
