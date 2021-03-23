#include <stdlib.h>

//
//  My implementation of C++ vector
//

template<typename T>
struct my_vector
{
    private:
        T *ptr;
        int sz = 0, N = 0;

    public:
        void resize( int new_N );
        void push_back( T data );
        int size();
        T& operator[] ( int idx );
};

//

template<typename T>
void my_vector<T>::resize( int new_N )
{
    //
    // Allocate a memory space with twice the current size
    //
    // Move the data & Free the current space
    //

    T *ptr_new = (T*)malloc(sizeof(T)*N);

    for(int i=0;i<sz;i++)
        ptr_new[i] = ptr[i];

    free(ptr);

    ptr = ptr_new;
}

//
//  Insert data & place it at the end of the list
//

template<typename T>
void my_vector<T>::push_back( T data )
{
    // resize the space if full
    if( !N )
        resize( N = 1 );
    else if ( sz == N )
        resize( N *= 2 );

    ptr[sz++] = data;
}

//

template<typename T>
int my_vector<T>::size()
{
    return sz;
}

//
// return the reference of array element
//

template<typename T>
T& my_vector<T>::operator[]( int idx )
{
    return ptr[idx];
}
