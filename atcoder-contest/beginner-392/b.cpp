#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

vector<int> lista(1007, 0);

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        lista[a] = 1;
    }

    vector<int> ans;

    int count = 0;
    for(int i = 0; i < 1007; i++)
    {
        if(lista[i] == 0 && i < n)
        {
            count++;
            ans.push_back(i+1);
        }
    }

    cout << count << '\n';
    for(auto p : ans) cout << p << " ";
    cout << '\n';

    return 0;
}