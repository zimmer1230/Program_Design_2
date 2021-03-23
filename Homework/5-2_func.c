/*  probID: W5-2-BinarySearch  */

int BinarySearch(int A[],int n, int k){
    int left = -1, right = n, mid;
    while ( left < right - 1){
        mid = (left + right)/2;
        if (A[mid]<k)
            left = mid;
        else
            right = mid;
    }
    return right;

}
