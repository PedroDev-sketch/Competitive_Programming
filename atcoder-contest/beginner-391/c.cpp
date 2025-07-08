#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

vector<int> nests(10e6+7, 1);
vector<int> pigeons(10e6+7);


signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    for(int i = 0; i < pigeons.size(); i++)
    {
        pigeons[i] = i;
    }

    int n, q, count = 0;
    cin >> n >> q;

    for(int i = 0; i < q; i++)
    {
        int qtype, p, h;
        cin >> qtype;

        if(qtype == 1)
        {
            cin >> p >> h;

            nests[pigeons[p]]--;
            
            if(nests[pigeons[p]] == 1) count--;

            pigeons[p] = h;
            nests[h]++;

            if(nests[h] == 2) count++;
        }
        else cout << count << '\n';
    }

    return 0;
}