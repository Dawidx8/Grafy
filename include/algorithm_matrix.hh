#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hh"
#include "constant.hh"


/* =====================================================
Plik ten zawiera delkaracje i opisy funckji uzywanych 
w celu przeprowadzania odpowienich operacji na grafie
przy uzyciu macierzy sasiedztwa.
======================================================== */


/* =====================================================
Funkcja bedaca zapisem algorytmu Dijkstry operujacego 
na macierzy sasiedztwa, ktora wyznacza sciezke od
dowolnego wierzcholka do wszystkich pozostalych 
w grafie wazonym. Funkcja ta  dodatkowo zapisuje 
otrzymane wyniki do pliku. W tej konfiguracji programu
funkcja ta zapisuje wyniki do pliku tylko dla ostatniego 
obiegu petli.
Input: liczba wierzcholkow w grafie, referencja do 
wskaznika na macierz sasiedztwa oraz numer wierzcholka
startowego.
Output: metoda typu void
======================================================== */
void dijkstra_matrix(int n, matrix* &M, int v, string nazwa, int ind);

/* =====================================================
Funkcja ta tworzy graf wazony w postaci macierzy 
sasiedztwa, ktory zczytuje z odpowiedniego pliku 
tekstowego.
Input: referencja do wskaznika na macierz sasiedztwa,
referencja do wskaznika na liste wierzcholkow, 
dwie rozne referencje do wskaznika na liste krawedzi,
referencja do zmiennej przechowujacej liczbe wierzcholkow,
referencja do zmiennej przechowujacej liczbe krawedzi 
Output: metoda typu void
======================================================== */
void load_graph_from_file_to_matrix(matrix* &M, vertex* &head_v, edge* &head_e, edge* &head_e1, int &n, int &m);

/* =====================================================
Funkcja ta tworzy graf wazony w postaci macierzy 
sasiedztwa, ktory tworzy przy uzyciu liczb 
pseudolosowych.
Input: referencja do wskaznika na macierz sasiedztwa,
referencja do wskaznika na liste wierzcholkow, 
dwie rozne referencje do wskaznika na liste krawedzi,
referencja do zmiennej przechowujacej liczbe wierzcholkow,
referencja do zmiennej przechowujacej liczbe krawedzi,
wartosc gestosci grafu typu double
Output: metoda typu void
======================================================== */
void load_random_graph_to_matrix(matrix* &M, vertex* &head_v, edge* &head_e, edge* &head_e1, int &n, int &m, double density);