#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

fstream f("date.in", ios :: in);

const int NMAX = 100;

int n, nr = 0;

pair<int, int> I[NMAX];/// vector de perechi care retine intervalele orare

int part[NMAX];/// vector care retine partitia corespunzaroare fiecarui interval

bool mark[NMAX];

void citire()/// citirea intervalelor
{
    f>>n;

    for(int i = 1;i <= n; i++)
        {int x, y;
            f>>x>>y;
            I[i].first = x;
            I[i].second = y;
            part[i] = 0;
        }

    f.close();
}

bool cmp(pair<int, int>i1, pair<int, int>i2)/// compararea a doua intervale dupa primul capat
{
    return i1.first < i2.first;
}

void partitionare()/// partitionarea multimii intervalelor
{
    sort(I + 1, I + n, cmp);/// sortam intervalele dupa primul capat

    for(int i = 1;i <= n; i++)/// alegem partitiile astfel incat iutr-o partitie sa nu existe intervale care sa se intersecteze
    {
        for(int j = 1; j <= n; j++)
            if(I[i].second < I[j].first)
               {
                   part[j] = ++nr;
                   part[i] = part[j];
               }
    }
}

void afisare()
{

    cout<<"Sunt necesare "<<nr<<" sali."<<'\n';

    for(int i = 1;i <= nr; i++)
    {
        cout<<"Sala "<<i<<" : ";
        for(int j = 1;j <= n; j++)
            if(part[j] == i)
               cout<<"["<<I[j].first<<", "<<I[j].second<<"]";
        cout<<'\n';
    }
}

int main()
{
    citire();

    partitionare();

    afisare();

    return 0;
}
