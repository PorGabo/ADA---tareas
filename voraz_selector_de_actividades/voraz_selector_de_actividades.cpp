//
//  main.cpp
//  voraz_seleccion_de_actividades
//
//  Created by Gabriel Rodriguez Postigo on 30/05/24.
//

#include <iostream>
#include <vector>
using namespace std;

// custom
bool comparition(const pair<int, int>& a, const pair<int, int>& b) //-1 es b-a, 1 es a-b
{
    return a.second < b.second;
}

void selector(vector<pair<int, int>>& actividades)
{
//    cout << "tareas iniciales: ";
//    for(auto i = actividades.begin() ; i!=actividades.end() ; i++)
//        cout << "{" << i->first << "," << i->second << "} ";
//    cout << endl;
    
    
    sort(actividades.begin(), actividades.end(), comparition);
    
    
//    cout << "tareas ordenadas: ";
//    for(auto i = actividades.begin() ; i!=actividades.end() ; i++)
//        cout << "{" << i->first << "," << i->second << "} ";
//    cout << endl;
    
    
    vector<pair<int, int>> answer;
    int last_scheduled = 0; //tiempo, añade el primero si o si
    for(auto i = actividades.begin() ; i!=actividades.end() ; i++)
    {
        if(last_scheduled <= i->first)
        {
            answer.push_back(*i);
            last_scheduled = i->second;
        }
    }
    
    cout << endl << "tareas seleccionadas: ";
    for(auto i = answer.begin() ; i!=answer.end() ; i++)
        cout << "{" << i->first << "," << i->second << "} ";
    cout << endl << endl ;
}

int main()
{
    vector<pair<int, int>> actividades = {{1,7},{2,5},{4,6},{4,9},{5,8},{7,11},{6,10},{9,12}}; //{h inicio,h fin}

    selector(actividades);
    
    return 0;
}
