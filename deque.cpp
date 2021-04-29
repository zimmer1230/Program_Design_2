/*
 *      Read a sequence and store it using deque
 *
 *          Use iterator to print the elements
 *
 *          Modify deque from its head
 */

#include <bits/stdc++.h>
using namespace std;

deque<int> q;

int main()
{
    int i,j,k;

    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &j);
        q.push_back(j);

        // or, you can also
        //
        // q.push_back(0);
        // scanf("%d", &q.back());
    }

    // print the elements using iterator

    auto it = q.begin();
    while( it < q.end() )
        printf("%d ", *it++);
    printf("\n");

    // print the element & pop it from the head

    while( !q.empty() )
    {
        printf("%d ", q.front());
        q.pop_front();
    }
    printf("\n");

    return 0;
}
