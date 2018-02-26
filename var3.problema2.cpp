#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream f("date.in", ios :: in);

const int NMAX = 100;

vector<int> *G;
vector<int> sol;

bool viz1[NMAX], viz2[NMAX];

int n, m;

void citire()/// citim arborele
{
    f>>n>>m;

    int x, y;

    G = new vector <int> [n + 1];

    for(int i = 1;i <= m; i++)
    {
        f>>x>>y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    f.close();
}

void dfs(int node)/// parcurgem arborele in adancime
{
    viz1[node] = true;

    int leaf = true; /// plecam dintr-o "frunza"

    for(int i = 0;i < G[node].size(); i++)/// parcurgem lista de adiacenta
    {
        if(!viz1[G[node][i]])
           {
               dfs(G[node][i]);

               if (viz2[G[node][i]] == false)/// stramosul nu este "frunza"
					leaf = false;
			}
	}

	if (leaf == false) /// in solutie retinem doar nodurile care sunt "frunze"
		viz2[node]= true;
	else
		sol.push_back(node);

}

void afisare()
{
    dfs(1);

	cout << sol.size() << "\n";
	for (unsigned int i = 0; i < sol.size(); ++i)
		cout << sol[i] << " ";
}


int main()
{
    citire();

    afisare();

    return 0;
}
