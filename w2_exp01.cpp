#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MaxN (int)1e5

int A[MaxN];
int n;

int cmp( const void *a, const void *b )
{
    return *(int*)a - *(int*)b;
}

//int lower_bound(int[],int,int); // return the index of the first element that is >= k
//int upper_bound(int[],int,int); // return the index of the first element that is > k

int main()
{
    int i,j,k;

    // read the input sequence
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);

    // sort the sequence
    //qsort(A,n,sizeof(int),cmp);

    // read the key to search
    scanf("%d", &k);
    iterator low=A;
     lower_bound(low,low+n,k);

    printf("The first element that is >= %d is %d\n", k, A[i]);
    printf("The first element that is > %d is %d\n", k, A[j]);

    printf("%d occurs %d times in the sequence\n", k, j-i);

    return 0;
}

// return the index of the first element that is >= k
//int lower_bound(int A[], int n, int k)
//{
//    int left = -1, right = n;
//
//    while( left < right -1 )
//    {
//        int mid = (left+right)/2;
//
//        if( A[mid] < k )
//            left = mid;
//        else
//            right = mid;
//    }
//
//    return right;
//}

// return the index of the first element that is > k
//int upper_bound(int A[], int n, int k)
//{
//    int left = -1, right = n;
//
//    while( left < right -1 )
//    {
//        int mid = (left+right)/2;
//
//        if( k < A[mid] )
//            right = mid;
//        else
//            left = mid;
//    }
//
//    return right;
//}
