#include <bits/stdc++.h>
#include "my-int-vector.h"
#include "my-vector.h"

using namespace std;

//

int main()
{
    int i,j,k;

    my_vector<int> seq;

    //  Read the sequence and store it into seq

    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &i);
        seq.push_back(i);
    }

    //  Print the sequence in reverse order

    for( i = seq.size()-1; i >= 0; i-- )
        printf("%d ", seq[i]);
    printf("\n");

    //

    return 0;
}
