#include <iostream>
#include <fstream>
#include <string>
#include "edge.hh"
#include "vertex.hh"


using namespace std;



edge::edge(int w)
{
    weight = w;
    start = end = nullptr;
    next = nullptr;
}


edge::~edge()
{
    delete start;
    delete end;
    delete next;
    start = end = nullptr;
    next = nullptr;
}


edge::edge()
{
    weight = 0;
    start = end = nullptr;
    next = nullptr;
}