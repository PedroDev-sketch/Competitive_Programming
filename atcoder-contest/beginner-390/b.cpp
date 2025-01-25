#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> in(n);

    for(auto& p : in) cin >> p;

    if(n == 2) 
    {
        cout << "Yes\n";
        return 0;
    }

    bool ans = true;
    for(int i = 0; i < n-2; i++)
    {
        if(in[i+1]*in[i+1] != in[i]*in[i+2]) ans = false;
    }

    if(ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}