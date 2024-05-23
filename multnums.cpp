//GabrielRP

#include <cmath>
#include <iostream>
#include <list>

using namespace std;

list<long> primeros(list<long> original, int tmn)
{
    tmn = (int)original.size() / 2;
    list<long> sol;
    int i = 0;
    for (auto iter = original.begin(); i < tmn; ++iter, i++)
    {
        sol.push_back(*iter);
    }
    return sol;
}

list<long> ultimos(std::list<long> original, int tmn)
{
    tmn = (int)original.size() / 2;
    list<long> sol;
    
    int totalElementos = (int)original.size();
    
    if (tmn > 0 && tmn <= totalElementos)
    {
        int startPoint = 0;
        if (totalElementos % 2 == 0)
            startPoint = totalElementos - tmn;
        else
            startPoint = totalElementos - (tmn + 1);
    
        auto iter = original.begin();
        advance(iter, startPoint);
    
        for (; iter != original.end(); ++iter)
        {
            sol.push_back(*iter);
        }
    }

    return sol;
}

list<long> resta(list<long> first, list<long> second)
{
    list<long> sol;
    bool changed = 0;
    int maxsize = (int)max(first.size(), second.size());
    int remaining = 0;

    if (maxsize > first.size())
    {
        int difference = maxsize - first.size();
        for (int i = 0; i < difference; i++)
        {
            first.push_front(0);
        }
    }
    if (maxsize > second.size())
    {
        int difference = maxsize - second.size();
        for (int i = 0; i < difference; i++)
        {
            second.push_front(0);
        }
    }
    if (*first.begin() < *second.begin())
    {
        list<long> tmp = first;
        first = second;
        second = tmp;
        changed = 1;
    }
    first.reverse();
    second.reverse();
    while (!first.empty() || !second.empty() || remaining != 0)
    {
        int a = 0;
        int b = 0;

        if (!first.empty())
        {
          a = first.front();
          first.pop_front();
        }

        if (!second.empty())
        {
            b = second.front();
            second.pop_front();
        }

        int diff = a - b - remaining;
        if (remaining)
          remaining--;
    
        if (diff < 0 && !second.empty())
        {
            diff += 10;
            remaining = 1;
        }
        else
        {
            remaining = 0;
        }
        if (changed)
        {
            sol.push_front(-diff);
        }
        else
        {
            sol.push_front(diff);
        }
    }
    return sol;
}

long mult(list<long> u, list<long> v, int tmn, int base) 
{
    if (v.size() == base && u.size() == base)
    {
        long sol = *(u.begin()) * *(v.begin());
        return sol;
    }
    list<long> w = primeros(u, tmn / 2);
    list<long> x = ultimos(u, tmn / 2);
    list<long> y = primeros(v, tmn / 2);
    list<long> z = ultimos(v, tmn / 2);

    long m1 = mult(w, y, tmn / 2, base);
    long m2 = mult(x, z, tmn / 2, base);
    long m3 = mult(resta(w, x), resta(z, y), tmn / 2, base);
    long sol;
    if (u.size() % 2 == 0 || u.size() == 1)
        sol = (((pow(10, max(u.size(), v.size())) * m1) + ((m1 + m2 + m3) * pow(10, max(u.size(), v.size()) / 2))) + m2);
    else
    {
        long p1 = pow(10, 2 * ((max(u.size(), v.size()) / 2) + 1)) * m1;
        long p2 = (m1 + m2 + m3) * pow(10, max(u.size(), v.size()) / 2 + 1);
        sol = (((p1) + (p2)) + m2);
    }
    return sol;
}

int main(int argc, const char *argv[])
{
    list<long> fst = {1, 2, 3, 4};
    list<long> scd = {5, 6, 7, 8};
    cout << mult(fst, scd, scd.size(), 1);
    return 0;
}
