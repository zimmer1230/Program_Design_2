#include <stdio.h>
#include <math.h>
int g(int);
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int n;

int main(){
    scanf("%d",&n);
    int x=2,y=2,d=1;
    while(d==1){
        x = g(x);
        y = g(g(y));
        d = gcd(abs(x-y),n);
    }
    printf("%d",d);





return 0;
}

int g(int x){
    return (x*x+1)%n;
}
