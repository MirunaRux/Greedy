#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct text
{
    float l, frecv, indice;
}x;

bool comp (text i, text j)  ///compara doua texte dupa lungime / frecventa
{
   return (i.l / i.frecv < j.l / j.frecv);
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    vector <text> v; ///vectorul de texte

    int n;

    f>>n; ///se citeste numarul de texte

    for(int i = 0;i < n; i++) ///se citesc datele despre texte
    {
        f>>x.l>>x.frecv;

        x.indice = i + 1;

        v.push_back(x); ///si se adauga in vector
    }

    sort (v.begin(), v.end(), comp); ///se sorteaza crescator textele dupa lungime / frecventa

    for(int i = 0;i < n; i++) /// se afiseaza vectorul sortat astfel
        g<<v[i].indice<<" ";

    f.close();
    g.close();

    return 0;
}
