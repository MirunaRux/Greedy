#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

struct text
{
    float l, frecv, indice;
}x;

bool comp (text i, text j) ///compara textele dupa lungime
{
   return (i.l < j.l);
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    vector <text> v; ///vectorul de texte

    int n,aux,p;

    f>>n>>p; ///n - nr de texte , p - nr de benzi

    vector <int> a[p+1]; ///matrice de texte pe cele p benzi

    for(int i = 0;i < n; i++) ///se citesc cele n texte
    {
        f>>x.l>>x.frecv;

        x.indice = i + 1;

        v.push_back(x);
    }

    sort(v.begin(), v.end(), comp); ///se sorteaza dupa lungime

     int i = 0;

     while(i < n)
        {
            aux = 0;
            while(aux < p && i < n)
              {
                  a[aux].push_back(v[i].indice);
                  aux++;
                  i++;
              }
        }

    for(int i = 0;i < p; i++)
    {
        for(vector <int> :: iterator it = a[i].begin();it != a[i].end(); ++it)
            g<<*it<<" ";
        g<<endl;
    }

    f.close();
    g.close();

    return 0;
}
