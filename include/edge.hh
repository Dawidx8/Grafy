#pragma once
#include <iostream>
#include "vertex.hh"

using namespace std;

/* =====================================================
Klasa edge modeluje pojecie krawedzi w grafie. 
Pola prywatne klasy: 
- waga danej krawedzi
- wierzcholek poczatkowy dla tej krawedzi
- wierzcholek koncowy dla tej krawedzi
- wskaznik na kolejny obiekt tej klasy
======================================================== */
class edge{
    private:
        double weight;
        vertex* start;
        vertex* end;
        edge* next;

    public:
        /* ======================================================
        Metoda ustawiajaca wartosc pola weight na wartosc
        rowna podanemu argumentowi.
        Input: waga krawedzi bedaca liczba typu double
        Output: metoda typu void
        ========================================================= */
        void insert_weight(double w) { weight = w; }

        /* ======================================================
        Metoda przypisujaca polom start i end adresy wierzcholkow 
        podanych jako argumenty.
        Input: dwa wskazniki na obiekty klasy vertex
        Output: metoda typu void
        ========================================================= */
        void insert_vertices(vertex* v1, vertex* v2) { start = v1; end = v2; }

        /* ======================================================
        Metoda przypisujaca polu next wskaznik na kolejny obiekt 
        klasy edge.
        Input: wskaznik na krawedz
        Output: metoda typu void
        ========================================================= */
        void insert_next_edge(edge* e) { next = e; }

        /* ======================================================
        Konstruktor parametryczny przypisujacy polu weight 
        wartosc podana w argumencie, a wszystkie pozostale pola
        wskaznikowe ustawiane sa na wartosc nullptr.
        ========================================================= */
        edge(int w);

        /* ======================================================
        Konstruktor bezparametryczny przypisujacy polu weight 
        wartosc rowna 0, a wszystkie pozostale pola
        wskaznikowe ustawiane sa na wartosc nullptr.
        ========================================================= */
        edge();

        /* ======================================================
        Destruktor usuwajacy obiekty znajdujace sie pod 
        polami wskaznikowymi i przypisujacy tym polom wartosc 
        nullptr.
        ========================================================= */
        ~edge();

        /* ======================================================
        Metoda zwracajaca wage krawedzi.
        Input: void
        Output: wartosc wagi danej krawedzi 
        ========================================================= */
        int get_weight() { return weight; }

        /* ======================================================
        Metoda zwracajaca pole next.
        Input: void
        Output: wskaznik na obiekt klasy edge
        ========================================================= */
        edge* get_next() { return next; }

        /* ======================================================
        Metoda ustawiajaca pole weight na wartosc podana jako 
        argument.
        Input: waga krawedzi typu double
        Output: metoda typu void 
        ========================================================= */
        void set_weight(int w) { weight = w; }

        /* ======================================================
        Metoda ustawiajaca pole next na wartosc podana jako 
        argument.
        Input: wskaznik na obiekt klasy edge
        Output: metoda typu void 
        ========================================================= */
        void set_next(edge* n) { next = n; }
  
        /* ======================================================
        Metoda zwracajaca wskaznik na wierzcholek poczatkowy.
        Input: void
        Output: wskaznik na obiekt klasy vertex 
        ========================================================= */
        vertex* get_start() { return start; }

        /* ======================================================
        Metoda zwracajaca wskaznik na wierzcholek koncowy.
        Input: void
        Output: wskaznik na obiekt klasy vertex 
        ========================================================= */
        vertex* get_end() { return end; }
};