#include <stdio.h>

#define MaxNM 500

int M[MaxNM][MaxNM];    // the input matrix and its dimension
int n,m;
// utility functions & row operations in Z2
int is_zero( int a );  // check if row a is a zero vector

void swap_row( int a, int b );  // swap row a and row b
void add_to( int a, int b );    // add row a into row b
//  Implement Gaussian Elimination
int gaussian_elimination();

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&M[i][j]);
        }
    }
    int independent = 0;

    for(int i=0;i<n;i++){
        if( is_zero(i))
            continue;
        independent++;
        for(int j=i+1;j<n;j++){
            for(int k=0;k<m;k++){
                if( (M[i][k] == 1) && (M[j][k] == 1) )
                    add_to( i, j );
            }
        }
    }

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%d ",M[i][j]);
//        }
//        printf("\n");
//    }

    printf("%d",independent);




return 0;
}

int is_zero(int a){
    for(int i=0;i<m;i++){
        if(M[a][i]==1)
            return 0;
    }
    return 1;
}
void add_to(int a,int b){
    for(int i=0;i<m;i++){
        M[b][i] = M[b][i] ^ M[a][i] ;
    }
}
