#include <iostream>
#include "matrix.hh"
#include <assert.h>

using namespace std;


edge* matrix::access_view(int i, int j)
{
    assert(i >= 0 && i < size && j >= 0 && j < size);
    return array[i][j];
}


void matrix::access_edit(int i, int j, edge* ptr)
{
    assert(i >= 0 && i < size && j >= 0 && j < size);
    array[i][j] = ptr;
}



matrix::matrix(int n)
{
    array = new edge** [n];
    size = n;

    for(int i=0;i<n;i++)
    {
        array[i] = new edge* [n];
        //array[i] = nullptr;
    }
}



matrix::~matrix()
{
    for(int i=0;i<size;i++)
        delete array[i];

    delete [] array;
}