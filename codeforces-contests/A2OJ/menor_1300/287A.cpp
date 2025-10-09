#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    
    vector<string> xs(4);
    for(auto& x : xs) cin >> x;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            char c = xs[i][j];
            ll f = 0;
            if(i+1 < 4 && xs[i+1][j]==c) f++;
            if(j+1 < 4 && xs[i][j+1]==c) f++;
            if(i+1 < 4 && j+1 < 4 && xs[i+1][j+1]==c) f++;

            if(f>=2 || !f)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
    
    return 0;
}