#include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <ctime>
#include <iomanip>
#include "algorithm_matrix.hh"
#include "algorithm_list.hh"


using namespace std;



int main()
{
    int n[5] = {160, 240, 320, 480, 560};      // liczba wierzcholkow
    int m = 0;                    // liczba krawedzi
    vertex* head_v = nullptr;     // wskaznik na liste werzcholkow
    edge* head_e = nullptr;       // wskaznik na liste krawedzi
    edge* head_e1 = nullptr;
    double density[4] = {0.25, 0.5, 0.75, 1.00};        // tablica gestosci grafu
    matrix* M[100];     // tablica wskaznikow na obiekty klasy matrix
    list** L[100];      // tablica podwojnych wskaznikow na obiekty klasy list
    double time = 0;
    double start = 0;
    double stop = 0;
    ofstream file;

    file.open("dat/time_matrix.txt", ios::out | ios::trunc);     // usuniecie tego co bylo w pliku odpowiednim dla macierzy sasiedztwa
    file.close();

    file.open("dat/time_list.txt", ios::out | ios::trunc);     // usuniecie tego co bylo w pliku odpowiednim dla listy sasiedztwa
    file.close();

    // MACIERZ SASIEDZTWA ====================================================================================================
    file.open("dat/time_matrix.txt", ios::out | ios::app);
    file << "Czas działania algorytmu Dijkstry dla macierzy sasiedztwa" << endl << endl;
    file << "l. wierzcholkow        gestosc grafu       czas" << endl;

    for(int i=0;i<5;i++)        // petla dla 5 ilosci wierzcholkow
    {
        for(int j=0;j<4;j++)        // petla dla 4 gestosci grafu
        {
            for(int k=0;k<100;k++)      // tworzenie 100 randomowych instancji listy sasiedztwa
            {
                load_random_graph_to_matrix(M[k],head_v,head_e,head_e1,n[i],m,density[j]);
            }

            start = clock();
            for(int k=0;k<100;k++)      
            {
                int ind = i*100 + j*10 + k;
                string nazwa = "dat/matrix_" + to_string(n[i]) + "_ " + to_string(density[j]) + ".dat";
                dijkstra_matrix(n[i],M[k],0,nazwa,ind);
            }
            stop = clock();
            time = (stop - start)/CLOCKS_PER_SEC;

            for(int k=0;k<100;k++)
                delete M[k];

            file << n[i] << "                       " << setprecision(2) << density[j] << "                 " << setprecision(6) << time << endl;
        }
    }

    file.close();
    // ======================================================================================================================== 


    // LISTA SASIEDZTWA =======================================================================================================
    file.open("dat/time_list.txt", ios::out | ios::app);
    file << "Czas działania algorytmu Dijkstry dla listy sasiedztwa" << endl << endl;
    file << "l. wierzcholkow        gestosc grafu       czas" << endl;

    for(int i=0;i<5;i++)        // petla dla 5 ilosci wierzcholkow
    {
        for(int j=0;j<4;j++)        // petla dla 4 gestosci grafu
        {
            for(int k=0;k<100;k++)      // tworzenie 100 randomowych instancji macierzy sasiedztwa
            {
                load_random_graph_to_list(L[k],head_v,head_e,head_e1,n[i],m,density[j]);
            }

            start = clock();
            for(int k=0;k<100;k++)      
            {
                int ind = i*100 + j*10 + k;
                string nazwa = "dat/list_" + to_string(n[i]) + "_ " + to_string(density[j]) + ".dat";
                dijkstra_list(n[i],L[k],0,nazwa,ind);
            }
            stop = clock();
            time = (stop - start)/CLOCKS_PER_SEC;

            file << n[i] << "                       " << setprecision(2) << density[j] << "                 " << setprecision(6) << time << endl;
        }
    }

    file.close();
    // =========================================================================================================================== 

    return 0;
}
