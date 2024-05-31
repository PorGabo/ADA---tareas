//
//  main.cpp
//  voraz_almacenamiento_en_cintas
//
//  Created by Gabriel Rodriguez Postigo on 30/05/24.
//

#include <iostream>
#include <vector>

using namespace std;

void almacenamientoOptimoEnCintas(vector<int>& ficheros)
{
    int n = (int)ficheros.size();

    sort(ficheros.begin(), ficheros.end());
    
    cout << "Orden optimo: ";
    for (int i = 0; i<n ; i++)
        cout << ficheros[i] << " ";
    cout << endl;
    
    int sumaParcial = 0;
    int sumaTotal = 0;
    
    for (int i = 0; i < n; ++i)
    {
        sumaParcial += ficheros[i];
        sumaTotal += sumaParcial;
    }
    cout << "suma: " << sumaTotal << endl;
    cout << "tmr: " << (double)sumaTotal/n << endl; //tiempo medio de recuperacion
    
}

int main()
{
    vector<int> ficheros = {5,10,3};
    almacenamientoOptimoEnCintas(ficheros);
    
    return 0;
}
