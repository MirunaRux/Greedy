#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream f("date.in", ios :: in);

const int NMAX = 100;

int secv[NMAX], n;
int s1, s2;
vector<int> v1, v2;

void citire()/// citim din fisier secventa
{
    f>>n;

    for(int i = 0;i < n; i++)
        f>>secv[i];

    f.close();
}

void determinare_sume()/// determinam sumele elementelor de pe pozitii impare(s1), respectiv pare(s2)
{
    for(int i = 0;i < n; i++)
        if(i%2 != 0)
            s1+=secv[i];
        else
            s2+=secv[i];
}

void simulare_joc()/// simulam jocul
{
   determinare_sume();/// calculam sumele

   int s = 0, d = n - 1;/// luam indicii de stanga si dreapta in capetele secventei
   int i;
   bool jucCur = false; /// 0 - randul primului jucator; 1 - randul celui de-al doilea jucator

   if(s1 > s2) /// verificam care suma este mai mare pentru a determina pozitia de pe care trebuie sa inceapa primul jucator ca sa castige
      i=1;
   else
      i=0;

    while(s <= d) /// cei doi jucatori aleg pe rand elemente din secventa (primul jucator alege elementele de pe pozitii impare daca s1>s2 si pare altfel)
    {
        if(jucCur == false)
        {
            if(s%2 == i)
            {
                v1.push_back(secv[s]);///in v1 retinem elementele alese de primul jucator
                s++;
            }
            else
            {
                v1.push_back(secv[d]);
                d--;
            }
        }
        else
        {
            if(secv[s] > secv[d])
            {
                v2.push_back(secv[s]);///in v2 retinem elementele alese de al doilea jucator
                s++;
            }
            else
            {
                v2.push_back(secv[d]);
                d--;
            }

        }
        jucCur = !jucCur;///schimbam jucatorul
    }
}

void afisare()
{
    cout<<"Primul jucator a ales : ";
    for(int i = 0;i < v1.size(); i++)
        cout<<v1[i]<<" ";
    cout<<'\n';
    cout<<"suma pentru primul jucator : ";
    if(s1 > s2)
        cout<<s1<<'\n';
    else
        cout<<s2<<'\n';

    cout<<"Al doilea jucator a ales : ";
    for(int i = 0;i < v2.size(); i++)
        cout<<v2[i]<<" ";
    cout<<'\n';
    cout<<"suma pentru al doilea jucator : ";
    if(s1 < s2)
        cout<<s1<<'\n';
    else
        cout<<s2<<'\n';

    cout<<"Primul jucator a castigat!"<<'\n';

}

int main()
{
    citire();
    simulare_joc();
    afisare();
    return 0;
}
