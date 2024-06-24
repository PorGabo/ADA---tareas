//
//  main.cpp
//  backtraking mochila binaria//
//  Created by Gabriel Rodriguez Postigo on 21/06/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Nodo 
{
    int nivel, peso, beneficio;

    Nodo(int nivel, int beneficio, int peso)
    {
        this->nivel = nivel;
        this->beneficio = beneficio;
        this->peso = peso;
    }
};

vector<int> pesos = { 2, 3, 4, 5 };
vector<int> beneficios = { 3, 4, 5, 6 };
int capacidad = 5;
int mejor_beneficio = 0;

void backtrack(Nodo* nodo)
{
    if (nodo->nivel == pesos.size())
    {
        if (nodo->beneficio > mejor_beneficio)
        {
            mejor_beneficio = nodo->beneficio;
        }
        return;
    }

    if (nodo->peso + pesos[nodo->nivel] <= capacidad)
    {
        Nodo* incluir = new Nodo(nodo->nivel + 1, nodo->beneficio + beneficios[nodo->nivel], nodo->peso + pesos[nodo->nivel]);
        backtrack(incluir);
    }
    Nodo* no_incluir = new Nodo(nodo->nivel + 1, nodo->beneficio, nodo->peso);
    backtrack(no_incluir);
}

int main()
{
    Nodo* raiz = new Nodo(0, 0, 0);
    backtrack(raiz);
    cout << "beneficio maximo: " << mejor_beneficio << endl;

    return 0;
}
