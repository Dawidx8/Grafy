#pragma once
#include <iostream>
#include "vertex.hh"
#include "edge.hh"

using namespace std;

/* =====================================================
Klasa list modeluje pojecie listy sasiedztwa dla
grafu. 
Pola prywatne klasy: 
- wskaznik na obiekt klasy edge
- wskaznik na kolejny element listy
======================================================== */
class list{
    private:
        edge* e;
        list* next;

    public:
        /* ======================================================
        Konstruktor bezparametryczny przypisujacy wszystkim 
        polom wskaznikowym wartosc nullptr.
        ========================================================= */
        list() { e = nullptr; next = nullptr; }

        /* ======================================================
        Destruktor usuwajacy obiekty znajdujace sie pod 
        polami wskaznikowymi i przypisujacy tym polom wartosc 
        nullptr.
        ========================================================= */        
        ~list();

        /* ======================================================
        Metoda zwracajaca pole e.
        Input: void
        Output: wskaznik na obiekt klasy edge
        ========================================================= */
        edge* get_e() { return e; }

        /* ======================================================
        Metoda zwracajaca pole next.
        Input: void
        Output: wskaznik na obiekt klasy list
        ========================================================= */
        list* get_next() { return next; }

        /* ======================================================
        Metoda ustawiajaca pole e na wartosc podana jako 
        argument.
        Input: wskaznik na obiekt klasy edge
        Output: metoda typu void 
        ========================================================= */
        void set_e(edge* e1) { e = e1; }

        /* ======================================================
        Metoda ustawiajaca pole next na wartosc podana jako 
        argument.
        Input: wskaznik na obiekt klasy edge
        Output: metoda typu void 
        ========================================================= */
        void set_next(list* l) { next = l; }
};



