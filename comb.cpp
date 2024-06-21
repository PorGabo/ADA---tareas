//
//  main.cpp
//  bt_combin
//
//  Created by Gabriel Rodriguez Postigo on 21/06/24.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> pesos = { 2, 3, 4, 5 };
vector<int> beneficios = { 3, 4, 5, 6 };
int cap = 5;
int m_b = 0; //best benefit

void combinatorio(int nivel, int peso_actual, int beneficio_actual)
{
    if (nivel == pesos.size())
    {
        if (beneficio_actual > m_b)
            m_b = beneficio_actual;
        return;
    }

    if (peso_actual + pesos[nivel] <= cap)
        combinatorio(nivel + 1, peso_actual + pesos[nivel], beneficio_actual + beneficios[nivel]);

    combinatorio(nivel + 1, peso_actual, beneficio_actual);
}

int main()
{
    combinatorio(0, 0, 0);
    cout << "beneficio maximo: " << m_b << endl;
    return 0;
}
