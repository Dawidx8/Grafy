#include <iostream>
#include <fstream>
#include <string>
#include "vertex.hh"

using namespace std;


vertex* vertex::check_vertex(int nr)
{
    vertex* ptr = this;

    while(ptr)
    {
        if(ptr -> number == nr)
            return ptr;
        
        ptr = ptr -> next;
    }

    return nullptr;
}



bool vertex::check_number(int nr)
{
    vertex* ptr = this;

    while(ptr)
    {
        if(ptr->number != nr)
            ptr = ptr -> next;

        else
            return false;
    }

    return true;
}



void vertex::insert_vertex(int nr)
{
    vertex* ptr = new vertex(nr);
    next = ptr;
    ptr = nullptr;
}



vertex::~vertex()
{
    if(next)
    {
        delete next;
        next = nullptr;
    }
}