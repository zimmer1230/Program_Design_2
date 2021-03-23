#include <stdio.h>

// a^n == ( a^((n-1)/2) )^2  * a or ( a^(n/2) )^2


//calculate a^n % p

long long fast_exp(long long ,long long);
int main(){


    long long a,n;
    long long result;
    scanf("%lld%lld",&a,&n);
    result = fast_exp(a,n);
    printf("%lld",result);






return 0;
}

long long fast_exp(long long a,long long n){
    if( n==0 )
        return 1;
    else if ( n % 2 == 0 ){
        long long result = fast_exp( a, n/2 );
        return result*result;
    }
    else{
        long long result = fast_exp( a, (n-1)/2 );
        return result*result*a;
    }


}
