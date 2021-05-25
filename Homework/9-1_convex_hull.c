#include<stdio.h>
#include<math.h>
int points[10005][2];  //points[][0] is x-axis, [][1] is y-axis;
int *wrap_order[10005];
int n;

void update_vect(int[],int[]);
long long cross_product(int[],int[]);
int main(){
    scanf("%d",&n);
    int *start_point;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&points[i][j]);  //i-th point
            if(i==0) start_point=points[i];
            else if( *(start_point)<=points[i][0] ){
                if( *(start_point)<points[i][0] )
                    start_point=points[i];
                else if(*(start_point+1)<points[i][1])
                    start_point=points[i];
            }
        }
    }
    wrap_order[0]=start_point;

    int node=1;
    for(int i=0;i<n;i++){
        if( i!=0 && wrap_order[i]==wrap_order[0] ) break;
        if(wrap_order[i]!=points[0]){
            int vect[3]={ *wrap_order[i]-points[0][0],*(wrap_order[i]+1)-points[0][1],0 };
            for(int j=1;j<n;j++){
                int cmp_vect[3]={ *wrap_order[i]-points[j][0],*(wrap_order[i]+1)-points[j][1],j };
                update_vect(cmp_vect,vect);
//                printf("vect is %d,%d,%d at i=%d,j=%d\n",vect[0],vect[1],vect[2],i,j);

            }
            wrap_order[i+1]=points[ vect[2] ];
        }
        else{
            int vect[3]={ *wrap_order[i]-points[1][0],*(wrap_order[i]+1)-points[1][1],0 };
            for(int j=0;j<n;j++){
                int cmp_vect[3]={ *wrap_order[i]-points[j][0],*(wrap_order[i]+1)-points[j][1],j };
                update_vect(cmp_vect,vect);
//                printf("vect is %d,%d,%d at i=%d,j=%d\n",vect[0],vect[1],vect[2],i,j);

            }
            wrap_order[i+1]=points[ vect[2] ];
        }
        node++;

    }

    printf("%d\n",node);
    for(int i=0;i<node;i++){
        printf("%d ", (wrap_order[i]-points[0])/2+1 );

    }





return 0;
}

void update_vect(int cmp_vect[],int vect[]){
    if( cross_product(cmp_vect,vect)>0 ){
        vect[0]=cmp_vect[0];
        vect[1]=cmp_vect[1];
        vect[2]=cmp_vect[2];
    }
    else if( cross_product(cmp_vect,vect)==0){
        if(abs(cmp_vect[0])>abs(vect[0]) || abs(cmp_vect[1])>abs(vect[1]) ){
            vect[0]=cmp_vect[0];
            vect[1]=cmp_vect[1];
            vect[2]=cmp_vect[2];
        }
    }

}

long long cross_product(int a[],int b[]){
    long long ans =(long long)a[0]*b[1] - (long long)a[1]*b[0];
//    printf("(%d,%d)x(%d,%d) cross ans is %lld\n",a[0],a[1],b[0],b[1],ans);
    return ans;
}
