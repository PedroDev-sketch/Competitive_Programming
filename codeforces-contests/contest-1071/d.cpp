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
    ll n; cin >> n;
    ll k = 1<<n; --k;
    multiset<ll> ans;
    map<ll,ll> hs;

    ll idx=0;
    for(ll i = k; i >= 0; i--)
    {
        if(i==k)
        {
            idx++;
            cout << i << " ";
            hs[i] = 1;
            ++k; k>>=1; --k;

            if(idx >= 3)
            {
                bitset<16> bt(i);
                ll j = 0;
                for(; j < 16; j++)
                    if(bt[j]==0)
                        break;

                //cout << "-> " << (1<<j) << " - " << (1<<(n-1)) << '\n';
                for(ll a = 1<<j; a < 1<<(n); a++)
                {
                    bitset<16> bt2(a);
                    bt2 |= bt;
                    ll num = bt2.to_ullong();
                    if(hs.count(num))
                        continue;
                    cout << num << " ";
                    hs[num]=1;
                }
            }
        }
        else
            ans.insert(i);
    }

    for(auto x : ans)
    {
        if(hs.count(x))
            continue;
        cout << x << " ";
    }
    
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
