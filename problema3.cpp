#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct sir
{
    vector <int> s;
};

int main()
{
    vector <int> v; ///sirul dat
    vector <int> u; ///u[i] - ultimul element adaugat in subsirul i
    int n,x;
    int ns = 0; ///nr de subsiruri

    cin>>n;
    sir a[n]; ///subsirurile

    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x); ///citim sirul initial
    }


    ns++; ///avem minim un subsir

    a[0].s.push_back(v[0]);///in primul subsir punem primul element

    u.push_back(v[0]);

    int mij,st,dr,gasit=0,k;

    for(int i=1; i<n; i++) ///se parcurg celelalte elemente din sirul initial
    {

       gasit = 0;
       st = 0;
       dr = ns-1;

       while (st <= dr) ///caut in vectorul u folosind cautarea binara
        {                             ///un subsir care se termina cu un element mai mare decat elementul curent
            int mij = (st + dr) / 2;
            if (u[mij] > v[i])
                {
                 dr = mij - 1;
                 gasit=1;
                 k=mij;
                }
            else
                st = mij + 1;
        }

       if(gasit) ///daca am gasit adaug elementul curent in subsir
       {
           u[k] = v[i];
           a[k].s.push_back(v[i]);
       }
       else ///daca nu creez un nou subsir
       {
           ns++;
           u.push_back(v[i]);
           a[ns-1].s.push_back(v[i]);
       }
    }

    for(int i=0; i<ns; i++) ///afisarea
    {
        for(int j=0; j<a[i].s.size(); j++)
            cout<<a[i].s[j]<<" ";
        cout<<endl;
    }
    return 0;
}
