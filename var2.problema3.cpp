#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct activitate ///pentru o activitate retinem
{
    float p; ///profitul
    float t; ///termenul limita
    int indice; ///indexul
}x;

bool comp(activitate i, activitate j) ///compara doua activitati dupa profit, iar daca profitul este egal, dupa termenul limita
{
   return ((i.p > j.p) || (i.p == j.p) && (i.t < j.t));

}

int a[1000]; ///retine indicii activitatilor care au fost selectate

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    vector <activitate> v; ///vector de activitati

    int n, i, j, ok; ///n - nr de activitati

    f>>n;

    for(int i = 0;i < n; i++) ///citim datele despre activitati
    {
        f>>x.p>>x.t;

        x.indice = i + 1;

        v.push_back(x);
    }

    sort (v.begin(), v.end(), comp); ///sortam activitatile descrescator dupa profit si crescator dupa termenul limita

    int profit = 0; ///profitul total initial este 0

    for(int i = 0;i < n; i++) ///parcurgem activitatile
       {
              ok = 0;
              j = v[i].t; ///luam termenul limita al activitatii curente

               while(!ok && j > 0) ///cat timp activitatea nu a fost selectata si termenul ei limita este > 0
                  {
                      if(a[j] == 0) ///daca pe pozitia j nu este nimic in a
                        {
                            a[j] = v[i].indice; ///adaugam indicele activitatii curente
                            ok = 1; ///o selectam
                            profit = profit + v[i].p; ///crestem profitul
                            cout<<"pe poz nu e nimic"<<j<<'\n';
                        }
                      else {
                            j--;cout<<"am scazut j -ul"<<'\n';}
                      ///altfel ii scadem termenul limita
                  }
       }

    for(int i = 1;i <= n; i++) ///afisam activitatile selectate
        if(a[i] != 0)
           g<<a[i]<<" ";

    g<<endl;
    g<<profit;

    f.close();
    g.close();

    return 0;
}
