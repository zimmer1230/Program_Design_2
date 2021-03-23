#include <stdlib.h>

//
//  My implementation of C++ vector
//

struct my_int_vector
{
    //
    //  private data & methods
    //
    private:
        int *ptr;
        int sz = 0, N = 0;

    //
    // public methods
    //
    public:
        void resize( int new_N );
        void push_back( int data );
        int size();
        int& operator[] ( int idx );
};

//

void my_int_vector::resize( int new_N )
{
    //
    // Allocate a memory space with twice the current size
    //
    // Move the data & Free the current space
    //

    int *ptr_new = (int*)malloc(sizeof(int)*new_N);

    for(int i=0;i<sz;i++)
        ptr_new[i] = ptr[i];

    free(ptr);

    ptr = ptr_new;
}

//
//  Insert data & place it at the end of the list
//
void my_int_vector::push_back( int data )
{
    // resize the space if full
    if( !N )
        resize( N = 1 );
    else if ( sz == N )
        resize( N *= 2 );

    ptr[sz++] = data;
}

//

int my_int_vector::size()
{
    return sz;
}

//
// return the reference of array element
//

int& my_int_vector::operator[]( int idx )
{
    return ptr[idx];
}
