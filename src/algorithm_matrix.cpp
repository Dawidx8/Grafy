#include <iostream>
#include "algorithm_matrix.hh"

using namespace std;


void dijkstra_matrix(int n, matrix* &M, int v, string nazwa, int ind)
{

    int cost[n] = {0};  // tablica kosztow dojscia do wierzcholkow
    int prev[n];        // tablica poprzednikow
    bool visited[n] = {0};  // tablica wierzcholkow odwiedzonych, visited [n] = true -> wierzcholek przetworzony 
                            // przez algorytm, visited[n] = fealse -> wierzcholek nieprzetworzony
    int previous[n] = {0};  // tablica potrzebna do zapisu sciezki do pliku
    int j = 0;
    int w = 0;
    edge * ptr = nullptr;
    int ind1 = 0;
    ofstream file;

    for(int i=0;i<n;i++)
    {
        cost[i] = inf;
        prev[i] = -1;
        visited[i] = false;
    }

    cost[v] = 0;


    for(int i=0;i<n;i++)        // petla przechodzaca po wszystkich wierzcholkach
    {
        for(j=0;visited[j];j++); // szukanie wierzcholka nieznajdujacego sie w zbiorze visited 

        for(w=j++;j<n;j++)
            if(!visited[j] && (cost[j] < cost[w]))
                w = j;

        visited[w] = true;   // znaleziony wierzcholek zostaje przeniesiony do zbioru visited

        for(int ind=0;ind<n;ind++)  // modyfikacja odpowiednich sasiadow w, ktorzy nie zostali odwiedzeni
        {
            ptr = M -> access_view(w,ind);
            if(ptr != nullptr)
                if(!visited[ptr->get_end()->get_number()] && (cost[ptr->get_end()->get_number()] > cost[w] + ptr->get_weight()))
                {
                    cost[ptr->get_end()->get_number()] = cost[w] + ptr->get_weight();
                    prev[ptr->get_end()->get_number()] = w;
                }
        }      
    }

    if(ind == 430)
    {
        file.open(nazwa, ios::out);

        if(file.good() == true)
        {
            file << "Wierzcholek startowy: " << v << endl << endl;

            for(int i=0;i<n;i++)
            {
                file << "Sciezka do wierzcholka " << i << ":  ";

                for(j=i;j>-1;j=prev[j])
                {
                    previous[ind1] = j;
                    ind1++;
                }
                    

                while(ind1)
                {
                    --ind1;
                    file << previous[ind1] << " ";
                }
                    

                file << endl << "Koszt: " << cost[i] << endl << endl;
            }

            file.close();
        } 

        else
        {
            cout << "Nieudana operacja zapisu wyniku do pliku" << endl;
            cout << "Sprobuj jeszcze raz uruchomic algorytm" << endl;
        }
    }
}





void load_graph_from_file_to_matrix(matrix* &M, vertex* &head_v, edge* &head_e, edge* &head_e1, int& n, int& m)
{
    ifstream file;
    file.open("dat/graf.dat", ios::in);
    int nr = 0;
    int first = 0;
    int last = 0;
    int weight = 0;

    if(file.good() == true)
    {
        file >> m >> n >> nr;

        head_v = new vertex(nr);
        vertex* ptr = head_v;
        vertex* ptr1 = nullptr;
        vertex* v1 = nullptr;
        vertex* v2 = nullptr;
        edge* e1 = nullptr;
        

        for(int i=0;i<m;i++)
        {
            file >> first >> last >> weight;

            if(head_v->check_number(first))
            {
                ptr1 = new vertex(first);
                ptr -> set_next(ptr1);
                ptr1 = nullptr;
                ptr = ptr -> get_next();
            }
                

            if(head_v->check_number(last))
            {
                ptr1 = new vertex(last);
                ptr -> set_next(ptr1);
                ptr1 = nullptr;
                ptr = ptr -> get_next();
            } 
        }

        file.close();


        file.open("dat/graf.dat", ios::in);
        file >> m >> n >> nr;
        head_e = new edge();
        head_e -> insert_vertices(head_v,0);
        

        file >> first >> last >> weight;    // pierwsza krawedz  
        head_e = new edge(weight);
        head_e1 = new edge(weight);
        v1 = new vertex(first);
        v2 = new vertex(last);
        head_e -> insert_vertices(v1,v2);
        head_e1 -> insert_vertices(v2,v1);
        edge* e = head_e;
        edge* e3 = head_e1;
        edge* e2 = nullptr;



        for(int i=1;i<m;i++)
        {
            file >> first >> last >> weight;
            v1 = new vertex(first);
            v2 = new vertex(last);
            e1 = new edge(weight);
            e2 = new edge(weight);
            e1 -> insert_vertices(head_v->check_vertex(first),head_v->check_vertex(last));
            e2 -> insert_vertices(head_v->check_vertex(last),head_v->check_vertex(first));
            e -> set_next(e1);
            e3 -> set_next(e2);
            e1 = nullptr;
            e2 = nullptr;
            e3 = e3 -> get_next();
            e = e -> get_next();
        }

        file.close();

        M = new matrix(n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            M -> access_edit(i,j,nullptr);

        edge* ind = head_e;

        while(ind)
        {
            int i = ind -> get_start() -> get_number();
            int j = ind -> get_end() -> get_number();
            M -> access_edit(i,j,ind);
            ind = ind -> get_next();
        }

        ind = head_e1;

        while(ind)
        {
            int i = ind -> get_start() -> get_number();
            int j = ind -> get_end() -> get_number();
            M -> access_edit(i,j,ind);
            ind = ind -> get_next();
        }

    }

        else
        {
            cout << " Nie udalo sie zaladowac grafu!" << endl;
        }
}






void load_random_graph_to_matrix(matrix* &M, vertex* &head_v, edge* &head_e, edge* &head_e1, int &n, int &m, double density)
{
    m = (int)(0.5*density*n*(n-1));     // wyliczona calkowita liczba krawedzi

    srand(time(NULL));

    head_v = new vertex(0);
    vertex* ptr = head_v;
    vertex* ptr1 = nullptr;

    for(int i=1;i<n;i++)        // lista wierzcholkow
    {
        ptr1 = new vertex(i);
        ptr -> set_next(ptr1);
        ptr1 = nullptr;
        ptr = ptr -> get_next();
    }

    vertex* ptr2 = nullptr;
    ptr = head_v;
    ptr2 = head_v;
    edge* p = head_e;
    edge* p1 = head_e1;
    int ind_m = 0;      // indeks krawedzi
    bool result = false;

   
    for(int i=0;i<n;i++)    // lista krawedzi
    {
        for(int j=i+1;j<n;j++)
        {
                
                    
            if(ind_m == 0)
            {
                int w = rand()%1000+1;
                head_e = new edge();
                head_e -> insert_weight(w);
                head_e -> insert_vertices(ptr->check_vertex(i),ptr2->check_vertex(j));
                p = head_e;
                ind_m++;

                head_e1 = new edge();
                head_e1 -> insert_weight(w);
                head_e1 -> insert_vertices(ptr->check_vertex(j),ptr2->check_vertex(i));
                p1 = head_e1;        
            }
                    
            else
            {
                int w = rand()%1000+1;
                edge* p2 = new edge();
                p2 -> insert_weight(w);
                p2 -> insert_vertices(ptr->check_vertex(i),ptr2->check_vertex(j));
                p -> set_next(p2);
                p = p -> get_next();
                p2 = nullptr;

                edge* p3 = new edge();
                p3 -> insert_weight(w);
                p3 -> insert_vertices(ptr->check_vertex(j),ptr2->check_vertex(i));
                p1 -> set_next(p3);
                p1 = p1 -> get_next();
                ind_m++;
                ptr = ptr2 = head_v;
                p3 = nullptr;
            } 

            if(ind_m >= m)
            {
                result = true;
                break;
            }
                
        }

        if(result)
            break;
    }


    p = head_e;
    M = new matrix(n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
           M -> access_edit(i,j,nullptr);

    edge* ind = head_e;
    int i = 0;
    int j = 0;

    while(ind)
    {
        i = ind -> get_start() -> get_number();
        j = ind -> get_end() -> get_number();
        M -> access_edit(i,j,ind);
        ind = ind -> get_next();
    }

    ind = head_e1;

    while(ind)
    {
        i = ind -> get_start() -> get_number();
        j = ind -> get_end() -> get_number();
        M -> access_edit(i,j,ind);
        ind = ind -> get_next();
    }   
}
