#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int num;
    set<int> lista;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        lista.insert(num);
    }

    if(lista.size() == n && *(lista.end()) == n) cout << "Yes";
    else cout << "No";
    cout << '\n';

    return 0;
}