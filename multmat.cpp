//GabrielRP

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
/* finding next square of 2*/
int nextPowerOf2(int k) { return pow(2, int(ceil(log2(k)))); }

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int newSize = size / 2;
        vector<vector<int>> A11(newSize, vector<int>(newSize)),
        A12(newSize, vector<int>(newSize)), A21(newSize, vector<int>(newSize)),
        A22(newSize, vector<int>(newSize)), B11(newSize, vector<int>(newSize)),
        B12(newSize, vector<int>(newSize)), B21(newSize, vector<int>(newSize)),
        B22(newSize, vector<int>(newSize)), c11(newSize, vector<int>(newSize)),
        c12(newSize, vector<int>(newSize)), c21(newSize, vector<int>(newSize)),
        c22(newSize, vector<int>(newSize)), R(newSize, vector<int>(newSize)),
        T(newSize, vector<int>(newSize)), Q(newSize, vector<int>(newSize)),
        S(newSize, vector<int>(newSize)), P(newSize, vector<int>(newSize)),
        V(newSize, vector<int>(newSize)), U(newSize, vector<int>(newSize)),
        fResult(newSize, vector<int>(newSize)),
        sResult(newSize, vector<int>(newSize));

        int i, j;

        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];
        
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }
        // P = (A11 + A22) * (B11 + B22)
        add(A11, A22, fResult, newSize);
        add(B11, B22, sResult, newSize);
        Strassen_algorithm(fResult, sResult, P, newSize);
    
        // Q = (A21 + A22) * B11
        add(A21, A22, fResult, newSize);
        Strassen_algorithm(fResult, B11, Q, newSize);
    
        // R = A11 * (B12 - B22)
        sub(B12, B22, sResult, newSize);
        Strassen_algorithm(A11, sResult, R, newSize);
    
        // S = A22 * (B21 - B11)
        sub(B21, B11, sResult, newSize);
        Strassen_algorithm(A22, sResult, S, newSize);
    
        // T = (A11 + A12) * B22
        add(A11, A12, fResult, newSize);
        Strassen_algorithm(fResult, B22, T, newSize);

        // U = (A21 - A11) * (B11 + B12)
        sub(A21, A11, fResult, newSize);
        add(B11, B12, sResult, newSize);
        Strassen_algorithm(fResult, sResult, U, newSize);
    
        // V = (A12 - A22) * (B21 + B22)
        sub(A12, A22, fResult, newSize);
        add(B21, B22, sResult, newSize);
        Strassen_algorithm(fResult, sResult, V, newSize);
    
        // c11 = P + S - T + V
        add(P, S, fResult, newSize);
        sub(fResult, T, sResult, newSize);
        add(sResult, V, c11, newSize);
    
        // c12 = R + T
        add(R, T, c12, newSize);
    
        // c21 = Q + S
        add(Q, S, c21, newSize);
    
        // c22 = P + R - Q + U
        add(P, R, fResult, newSize);
        sub(fResult, Q, sResult, newSize);
        add(sResult, U, c22, newSize);
    
        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

void multiplicar(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    vector<vector<int>>
    A = { {5, 3, 4, 1}, {5, 6, 1, 8}, {9, 1, 1, 2}, {3, 4, 5, 1} };
    vector<vector<int>>
    B = { {7, 1, 9, 2}, {1, 2, 3, 2}, {5, 2, 1, 2}, {9, 1, 1, 2} };
    int size = A.size();
    vector<vector<int>> X(size, vector<int>(size));

    Strassen_algorithm(A, B, X, size); //guardo en X

    vector<vector<int>>
    D = { {5, 3, 4, 1}, {5, 6, 1, 8}, {9, 1, 1, 2}, {3, 4, 5, 1} };
    vector<vector<int>>
    E = { {7, 1, 9, 2}, {1, 2, 3, 2}, {5, 2, 1, 2}, {9, 1, 1, 2} };

    vector<vector<int>> Y(A.size(), vector<int>(A.size()));
    multiplicar(D, E, Y); //guardo en Y

    cout << endl << "Sin Strassen" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Y[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nCon Strassen" << endl;

    // Imprimir el resultado
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
