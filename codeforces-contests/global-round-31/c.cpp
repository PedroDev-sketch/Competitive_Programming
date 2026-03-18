#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n, k; cin >> n >> k;
    vector<pair<bitset<64>, ll>> xs(k, {0, 0});

    if(k > 1 && !(k&1))
    {
        bitset<64> bt(n), bt2(0);
        
        for(ll i = 64; i >= 0; i--)
        {
            ll num = bt2.to_ullong(), skip = 0;

            queue<ll> idxs;
            for(ll j = 0; j < k; j++)
            {
                if(xs[j].ss < num)
                    idxs.push(j);
                else
                    skip = j;
            }

            if(bt[i])
            {
                bt2[i] = 1;
                num = bt2.to_ullong();
                
                for(ll j = 0; j < k; j++)
                {
                    if(j==skip) 
                        continue;
                    
                    xs[j].ff[i] = 1;
                    xs[j].ss = xs[j].ff.to_ullong();
                }
            }

            else
            {       
                while(idxs.size() >= 2)
                {
                    ll idx1 = idxs.front(); idxs.pop();
                    ll idx2 = idxs.front(); idxs.pop();

                    xs[idx1].ff[i] = 1;
                    xs[idx1].ss = xs[idx1].ff.to_ullong();

                    xs[idx2].ff[i] = 1;
                    xs[idx2].ss = xs[idx2].ff.to_ullong();
                }
            }
        }
    }

    else
    {
        while(k--)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for(auto x : xs) 
        cout << x.ss << " ";
    cout << '\n';   
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
