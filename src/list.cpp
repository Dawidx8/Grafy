#include <iostream>
#include "list.hh"

using namespace std;



list::~list()
{   
    if(e)
        delete e;

    if(next)
        delete next;

    next = nullptr;
    e = nullptr;
}