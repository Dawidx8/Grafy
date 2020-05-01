#pragma once
#include <iostream>
#include "edge.hh"
#include <assert.h>

using namespace std;


/* =====================================================
Klasa matrix modeluje pojecie macierzy sasiedztwa dla
grafu. 
Pola prywatne klasy: 
- potrojny wskaznik na obiekt klasy edge
- rozmiar tablicy = ilosc wierzcholkow w grafie
======================================================== */
class matrix{
    private:
        edge*** array;     
        int size;

    public:
        /* =====================================================
        Konstruktor parametryczny tworzacy dwuwymiarowa tablice 
        dynamiczna (n x n) o rozmiarze podanym w argumencie 
        ======================================================== */
        matrix(int n);

        /* =====================================================
        Destruktor usuwajacy obiekty stworzone na wskazniku 
        array. 
        ======================================================== */
        ~matrix();

        /* =====================================================
        Metoda zwraca konkretna komorke macierzy 
        sasiedztwa.
        Input: indeksy odpowiedniej komorki typu int
        Output: wskaznik na obiekt klasy edge
        ======================================================== */
        edge* access_view(int i, int j);

        /* =====================================================
        Metoda daje dostep do konkretnej komorki macierzy 
        sasiedztwa i w jej miejsce wspisuje podany wskaznik.
        Input: indeksy odpowiedniej komorki typu int, wskaznik 
        na obiekt klasy edge
        Output: metoda typu void
        ======================================================== */
        void access_edit(int i, int j, edge* ptr);
};
