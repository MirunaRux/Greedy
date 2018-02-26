#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;

struct cub ///pentru un cub retinem
{
    int l; ///lungimea laturii
    int c; ///culoarea
    int indice; ///indexul
}x;

bool comp(cub i, cub j) ///compara doua cuburi dupa lungimea laturii
{
   return (i.l > j.l);
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    vector <cub> v; ///vector de cuburi

    int n, p, s = 0; ///n - nr de cuburi p - numarul de culori

    f>>n>>p;

    for(int i = 0;i < n; i++) ///se citesc informatiile despre cuburi
    {
        f>>x.l>>x.c;
        x.indice = i + 1;
        v.push_back(x);
    }

    sort (v.begin(), v.end(), comp); ///se sorteaza cuburile descrescator dupa lungimea laturii

    int i = 0;

    while(i < n) ///parcurgem cuburile sortate
    {
        g<<v[i].indice<<" "; ///afisam cubul curent

        s = s + v[i].l; ///ii adaugam lungimea laturii la suma

        int urmator = i++; ///luam urmatorul cub

        if(v[urmator].c == v[i].c) ///daca are aceeasi culoare cu cel curent
           i+= 2; ///trecem peste el
        else
           i++; ///daca nu trecem la el si urmeaza sa il afisam
    }

    g<<endl;
    g<<s;

    f.close();
    g.close();

    return 0;
}
