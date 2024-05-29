#include <iostream>
#include <vector>
using namespace std;

// custom
bool comparition(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

vector<pair<int,int>> planificador(int T, vector<pair<int, int>>& tareas, int n)
{
    sort(tareas.begin(), tareas.end(), comparition);
    vector<pair<int, int>> answer;
    int pos = 1;
    for(auto i = tareas.begin(); pos<=T && i!=tareas.end();i++)
    {
        if (pos <= i->second)
        {
            answer.push_back(*i);
            pos++;
        }
    }
    return answer;
}

int main()
{
    vector<pair<int, int>> tareas = {{20, 3}, {15, 1}, {10, 1}, {7, 3}, {5, 1}, {3, 3}};
    int n = (int)tareas.size();
    int T = 4; // max

    vector<pair<int, int>> X = planificador(T, tareas, n);
    
    cout << "orden: ";
    for(int i = 0; i < X.size() ; i++)
        cout << "{" << X[i].first << "," << X[i].second << "} ";
    cout << "\n";
    return 0;
}
