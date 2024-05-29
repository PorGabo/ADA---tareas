#include <iostream>
using namespace std;

void mochila(int M, float b[], float p[], float X[], int n)
{
    // answer array with 0s
    for (int i = 0; i < n; i++)
        X[i] = 0;
    
    int pesoAct = 0;
    while (pesoAct < M)
    {
        //best object benefit/weight
        int i = 0; //best index
        double bestProportion = 0;
        for (int j = 0; j < n; j++)
        {
            double divition = b[j]/(double)p[j];
            if ( divition > bestProportion && (X[j] != 1))
            {
                i = j;
                bestProportion = b[i]/p[i];
            }
                
        }
        if (pesoAct + p[i] <= M)
        {
            X[i] = 1;
            pesoAct += p[i];
        }
        else
        {
            X[i] = (M-pesoAct)/(float)p[i];
            pesoAct = M;
        }
    }
    
}

int main()
{
    float p[] = {10,3,2,3}; //pesos
    float b[] = {10,9,9,9}; //beneficio
    int n = sizeof(p) / sizeof(p[0]);
    float X[n];
    int M = 10;
    
    
    
    mochila(M, b, p, X, n);
    
    cout << "pesos: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << "\n";
    cout << "beneficios: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
    
    cout << "Relacion beneficio/peso: ";
    for (int i = 0; i < n; i++)
        cout << ((double)b[i])/((double)p[i]) << " ";
    cout << "\n\n";
    
    cout << "USARE: ";
    for (int i = 0; i < n; i++)
        cout << X[i] << " ";
    cout << "\n\n";
    
    return 0;
}
