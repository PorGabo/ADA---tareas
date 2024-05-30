//
//  main.cpp
//  voraz_prim
//
//  Created by Gabriel Rodriguez Postigo on 29/05/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Grafo
{
    int V;
    vector<vector<pair<int, int>>> x;

    Grafo(int V)
    {
        this->V = V;
        x.resize(V);
    }

    void insertarArista(int a, int b, int peso)
    {
        x[a].push_back({b, peso}); // a hacia b
        x[b].push_back({a, peso}); // b hacia a
    }

    void prim(int initial_node)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(V, INT_MAX); // pesos min para cada nodo, inicio con grande
        vector<int> parent(V, -1); // vertices
        vector<bool> inMST(V, false); // si marco vertice, lo incluire

        pq.push({0, initial_node});
        key[initial_node] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (auto &[v, weight] : x[u])
            {
                if (!inMST[v] && key[v] > weight)
                {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        //print
        int sum = 0;
        for (int i = 0; i < V; ++i)
        {
            if (i != initial_node && parent[i] != -1)
            {
                cout << char('A' + parent[i]) << " - " << key[i] << " - " << char('A' + i) << endl;
                sum += key[i];
            }
        }
        cout << "Suma: " << sum << endl;
    }
};

int main()
{
    Grafo G(9); // A - I
    G.insertarArista(0, 1, 5);  // A - B
    G.insertarArista(0, 3, 6);  // A - D
    G.insertarArista(0, 2, 4);  // A - C
    G.insertarArista(1, 3, 7);  // B - D
    G.insertarArista(1, 8, 12); // B - I
    G.insertarArista(2, 3, 8);  // C - D
    G.insertarArista(2, 4, 9);  // C - E
    G.insertarArista(3, 5, 3);  // D - F
    G.insertarArista(3, 6, 4);  // D - G
    G.insertarArista(4, 6, 7);  // E - G
    G.insertarArista(4, 7, 10); // E - H
    G.insertarArista(5, 8, 5);  // F - I
    G.insertarArista(6, 8, 5);  // G - I
    G.insertarArista(6, 7, 6);  // G - H
    G.insertarArista(8, 7, 11); // I - H

    G.prim(1); // 0 es A, 1 es B

    return 0;
}
