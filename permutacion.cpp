//
//  main.cpp
//  permutacion
//
//  Created by Gabriel Rodriguez Postigo on 21/06/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pesos = { 2, 3, 4, 5 };
vector<int> beneficios = { 3, 4, 5, 6 };

int capacidad = 6;
int mejor_beneficio = 0;

void permutaciones(vector<int>& indices, int inicio, int fin)
{
    if (inicio == fin)
    {
        // Evaluamos la permutación actual
        int beneficio_actual = 0;
        int peso_actual = 0;
        for (int i = 0; i < indices.size(); ++i)
        {
            int index = indices[i];
            if (peso_actual + pesos[index] <= capacidad)
            {
                peso_actual += pesos[index];
                beneficio_actual += beneficios[index];
            }
            else
            {
                break;
            }
        }

        if (beneficio_actual > mejor_beneficio)
        {
            mejor_beneficio = beneficio_actual;
        }
    }
    else
    {
        for (int i = inicio; i <= fin; ++i)
        {
            swap(indices[inicio], indices[i]);
            permutaciones(indices, inicio + 1, fin);
            swap(indices[inicio], indices[i]);
        }
    }
}

int main()
{
    vector<int> indices(pesos.size());
    
    for (int i = 0; i < pesos.size(); ++i)
        indices[i] = i;
    
    permutaciones(indices, 0, (int)indices.size() - 1);
    cout << "beneficio maximo: " << mejor_beneficio << endl;

    return 0;
}
