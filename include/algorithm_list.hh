#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "list.hh"
#include "constant.hh"

/* =====================================================
Plik ten zawiera delkaracje i opisy funckji uzywanych 
w celu przeprowadzania odpowienich operacji na grafie
przy uzyciu listy sasiedztwa.
======================================================== */


/* =====================================================
Funkcja bedaca zapisem algorytmu Dijkstry operujaca na 
liscie sasiedztwa, ktora wyznacza najkrotsza sciezke 
od dowolnego wierzcholka do wszystkich pozostalych 
w grafie wazonym. Funkcja ta dodatkowo zapisuje 
otrzymane wyniki do pliku. W tej konfiguracji programu
funkcja ta zapisuje wyniki do pliku tylko dla ostatniego 
obiegu petli.
Input: liczba wierzcholkow w grafie, referencja do 
wskaznika na macierz sasiedztwa oraz numer wierzcholka
startowego.
Output: metoda typu void
======================================================== */
void dijkstra_list(int n, list** L, int v, string nazwa, int ind);

/* =====================================================
Funkcja ta tworzy graf wazony w postaci listy 
sasiedztwa, ktory zczytuje z odpowiedniego pliku 
tekstowego.
Input: referencja do wskaznika na liste sasiedztwa,
referencja do wskaznika na liste wierzcholkow, 
dwie rozne referencje do wskaznika na liste krawedzi,
referencja do zmiennej przechowujacej liczbe wierzcholkow,
referencja do zmiennej przechowujacej liczbe krawedzi 
Output: metoda typu void
======================================================== */
void load_graph_from_file_to_list(list** &L, vertex* &head_v, edge* &head_e, int& n, int& m);

/* =====================================================
Funkcja ta tworzy graf wazony w postaci listy 
sasiedztwa, ktory tworzy przy uzyciu liczb 
pseudolosowych.
Input: referencja do wskaznika na liste sasiedztwa,
referencja do wskaznika na liste wierzcholkow, 
dwie rozne referencje do wskaznika na liste krawedzi,
referencja do zmiennej przechowujacej liczbe wierzcholkow,
referencja do zmiennej przechowujacej liczbe krawedzi,
wartosc gestosci grafu typu double
Output: metoda typu void
======================================================== */
void load_random_graph_to_list(list** &L, vertex* &head_v, edge* &head_e, edge* &head_e1, int &n, int &m, double density);