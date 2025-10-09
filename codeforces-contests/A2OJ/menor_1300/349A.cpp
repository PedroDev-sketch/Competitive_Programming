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
    
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;

    vll ch{0,0,0}; bool ans = true;
    for(auto x : xs)
    {
        if(x==50)
        {
            ch[0]--;
            ch[1]++;
        }
        else if(x==100)
        {
            if(ch[1]) {ch[1]--; ch[0]--;}
            else ch[0]-=3;
        }
        else ch[0]++;

        for(auto c : ch)
            if(c<0)
            {
                ans=false;
                break;
            }
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}