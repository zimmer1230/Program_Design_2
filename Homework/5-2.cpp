#include <stdio.h>
#include <algorithm>

using namespace std;

int BinarySearch(int[],int,int);

int A[100000], n;

int main()
{
    int k, i, m;

    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &k);

        i = BinarySearch(A, n, k);
        printf("%d ", i);
        if( i >= 0 && i<n && A[i]==k )
            printf("Found!\n");
        else
            printf("not found\n");
    }

    return 0;
}





/*  probID: W5-2-BinarySearch  */

int BinarySearch(int A[],int n, int k){
    return lower_bound(A,A+n,k)-A;


//    int left = -1, right = n, mid;
//    while ( left < right - 1){
//        mid = (left + right)/2;
//        if (A[mid]<k)
//            left = mid;
//        else
//            right = mid;
//    }
//    return right;

}
