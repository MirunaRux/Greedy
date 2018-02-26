#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct activitate ///pentru fiecare activitate retinem
{
    int l; ///durata
    int t; ///termenul limita
    int nr; ///numarul initial al activitatii
};

bool compare(const activitate &i, const activitate &j) ///functie care comapara doua activitati dupa termenul limita
{
    return i.t < j.t;
}


int main()
{
    vector <activitate> a; ///vector de activitati

    int n;
    cout<<"nr de activitati: ";
    cin>>n;

    for(int i=0; i<n; i++) ///citirea datelor despre activitati
    {
        activitate v; ///pentru o activitate cunoastem

        cout<<"Durata activ "<<i+1<<": "; ///durata
        cin>>v.l;

        cout<<"Termen limita activ "<<i+1<<": "; ///termenul limita
        cin>>v.t;
        cout<<endl;

        v.nr = i+1;

        a.push_back(v);
    }

    int start = 0, end_i, p; ///start = ora de inceput a primei activitati programate

    int max = -1, nr_a;

    sort(a.begin(),a.end(),compare); ///se sorteaza activitatile dupa termenul limita al fiecaria in ordine crescatoare

    for(int i=0; i<n; i++)
        {
              end_i = start + a[i].l; ///calculam ora de final a activitatii i

              cout<<"activitatea "<<a[i].nr<<": intervalul "<<start<<" "<<end_i;

              p = end_i - a[i].t; ///calculam intarzierea activitatii i
              cout<<" intarziere "<<p;

              if(p > max) /// daca intarzierea activitatii i este maxima(pana la acest pas)
                {
                   max = p;
                   nr_a = a[i].nr; ///se retine aceasta activitate pentru ca intarzierea ei este maxima pana acum
                }
              start = end_i; ///ora de inceput a urmatoarei activitati este ora de final a activitatii curente
              cout<<endl;
        }
    cout<<"Intarziere planificare "<<nr_a;

    return 0;
}
