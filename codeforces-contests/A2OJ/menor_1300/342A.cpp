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

void backtrack()
{

}

signed main()
{
    fio;
    
    ll n;
    cin >> n;

    vll xs(n); map<ll,ll> hs;
    for(auto& x : xs) {cin >> x; hs[x]++;}

    ll ans = 0;
    vvll gs{{1, 2, 4}, {1, 2, 6}, {1, 3, 6}};
    vll gs_guide{0, 0, 0};

    if(hs[1] >= hs[4] && hs[2] >= hs[4]) 
    {
        gs_guide[0] = hs[4];
        hs[1] -= hs[4];
        hs[2] -= hs[4];
        hs[4] = 0;
    }

    if(hs[1] >= hs[3] && hs[6] >= hs[3])
    {
        gs_guide[2] = hs[3];
        hs[1] -= hs[3];
        hs[6] -= hs[3];
        hs[3] = 0;
    }

    if(hs[1] == hs[2] && hs[1] == hs[6])
    {
        gs_guide[1] = hs[1];
        hs[1] = hs[2] = hs[6] = 0;
    }

    for(auto [h, k] : hs)
    {
        if(k != 0) 
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        while(gs_guide[i])
        {
            gs_guide[i]--;

            for(auto g : gs[i]) cout << g << " ";
            cout << '\n';
        }
    }

    return 0;
}