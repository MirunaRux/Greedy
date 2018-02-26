#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j) ///functie care compara doua intervale dupa capatul din stanga
{
    return i.first < j.first;
}

int main()
{
    int n,a,b; ///n = nr de intervale, a,b - capetele intervalului

    vector < pair<int, int> > v; ///vector de intervale

    pair<int, int> inv; ///intervalul dorit
    cout<<"intervalul: ";
    cin>>a>>b;
    inv.first = a;
    inv.second = b;

    cout<<endl;

    cout<<"nr de intervale="; cin>>n;

    for(int i=0; i<n; i++) ///se citesc cele n intervale
    {
        cout<<"intervalul "<<i+1<<": ";
        cin>>a>>b;
        cout<<endl;
        v.push_back(pair<int, int> (a,b));
    }

    sort(v.begin(),v.end(),compare); ///se sorteaza dupa capatul din stanga

    int i = 0,k;
    int start = inv.first; ///se retine capatul din stanga al intervalului ramas de acoperit
    int maxim = -1;

    while (i < n && maxim < inv.second) /// se parcurg intervalele (cele n)
     {
            if (v[i].second <= start) ///daca intervalul curent nu se intersecteaza cu intervalul dorit
              i++; ///trecem la urmatorul interval

            else ///altfel
              {
                     if (v[i].first > start) ///daca intervalul curent nu contine capatul din stanga al intervalului dorit
                       break; ///problema nu are solutie -> afisam -1

                     while (i < n && maxim < inv.second && v[i].first <= start) ///altfel cautam in continuare primul interval care
                        {                                  /// contine si capatul din stanga al intervalului dorit si are capatul din dreapta
                                if (v[i].second > maxim) /// mai mare decat capatul din dreapta al intervalului dorit
                                 {
                                     maxim = v[i].second;
                                     k=i;
                                 }

                                i++;
                        }
                     cout<<v[k].first<<" "<<v[k].second<<endl; ///daca nu am gasit un interval care sa il includa pe cel dorit, afisam intervalul care contine
                                /// o parte din intervalul dorit, dar daca am gasit il afisam si in continuare nu o sa se mai afiseze nimic pana la final
                    start = maxim; /// si continuam cautarea de la capatul din dreapta al intervalului afisat

              }
     }

    return 0;
}
