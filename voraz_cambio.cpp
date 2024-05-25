#include <iostream>
using namespace std;

int calculateChange(int P, int C[], int n, int X[])
{
    int act = 0; // acumulado
    int j = n - 1; // index

    // answer array with 0s
    for (int i = 0; i < n; i++)
    {
        X[i] = 0;
    }

    while (act != P)
    {
        while ((C[j] > (P - act)) && (j > 0))
        {
            j--;
        }

        if (j < 0) //lo cambie
        {
            cout << "No existe solución\n";
            return -1;
        }

        X[j] = (P - act) / C[j];
        act += C[j] * X[j];
        j--;
    }

    // print
    cout << "The change to " << P << " is\n";
    for (int i = 0; i < n; i++)
    {
        if (X[i] != 0)
        {
            cout << X[i] << " coin of " << C[i] << " cents\n";
        }
    }

    return 0;
}

int main()
{
    int P = 591; // to pay 5.91 euros
    int C[] = {1,2,5,10,20,50,100,200}; // coins
    int n = sizeof(C) / sizeof(C[0]);
    int X[n]; // to store answer
    calculateChange(P, C, n, X);
    return 0;
}
