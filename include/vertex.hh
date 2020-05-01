#pragma once
#include <iostream>

using namespace std;


/* =====================================================
Klasa vertex modeluje pojecie wierzcholka w grafie. 
Pola prywatne klasy: 
- numer wierzcholka
- wskaznik na kolejny obiekt tej klasy
======================================================== */
class vertex{
    private:
        int number;
        vertex* next;

    public:
        /* ======================================================
        Metoda tworzaca na polu next nowy obiekt tej klasy 
        o numerze rownym argumentowi.
        Input: numer wierzcholka bedacy liczba calkowita
        Output: metoda typu void
        ========================================================= */
        void insert_vertex(int nr);

        /* ======================================================
        Metoda zwracajaca numer wierzcholka.
        Input: void
        Output: numer wierzcholka 
        ========================================================= */
        int get_number() { return number; }

        /* ======================================================
        Metoda zwracajaca wskaznik na kolejny wierzcholek.
        Input: void
        Output: wskaznik na obiekt klasy vertex 
        ========================================================= */
        vertex* get_next() { return next; }

        /* ======================================================
        Metoda ustawiajaca pole number na wartosc rowna jej
        argumentowi.
        Input: numer wierzcholka bedacy liczba calkowita
        Output: metoda typu void
        ========================================================= */
        void set_number(int nr) { number = nr; }

        /* ======================================================
        Metoda ustawiajaca pole next na wartosc rowna jej
        argumentowi.
        Input: wskaznik na obiekt klasy vertex
        Output: metoda typu void
        ========================================================= */
        void set_next(vertex* n) { next = n; }

        /* ======================================================
        Konstruktor parametryczny, ktory ustawia wartosc pola
        number na wartosc podana w argumencie, a polu
        wskaznikowemu przypisuje nullptr.
        ========================================================= */
        vertex(int nr) { number = nr; next = nullptr; }

        /* ======================================================
        Destruktor usuwajacy obiekt znajdyjacy sie pod 
        wskaznikiem next.
        ========================================================= */
        ~vertex();

        /* ======================================================
        Metoda sprawdzajaca, czy jakikolwiek wierzcholek ma numer 
        rowny numerowi podanemu w jej argumencie.
        Input: numer wierzcholka bedacy liczba calkowita
        Output: wartosc logiczna 
        ========================================================= */
        bool check_number(int nr);

        /* ======================================================
        Metoda sprawdzajaca, ktory wierzcholek ma numer rowny
        numerowi podanemu w jej argumencie.
        Input: numer wierzcholka bedacy liczba calkowita
        Output: wskaznik na obiekt klasy wierzcholek lub nullptr
        ========================================================= */
        vertex* check_vertex(int nr);
};