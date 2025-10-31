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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n; cin >> n;
    map<ll, ll> hs;
    vll xs(n); for(auto& x : xs) {cin >> x; hs[x]++;}
    ll top = 0, bottom = 0;
    ll sides = 0, lines = 0;

    ll sum = 0;
    ll odd = 0;
    for(auto h : hs)
        if(h.second%2)
            odd++;
    
    for(auto& [k, v] : hs)
    {
        if(v>0)
        {
            ll fq = v;
            if(fq%2)
            {
                v = 1;
                fq--;
            }
            sides+=fq*k;
            sum+=fq*k;
            lines += fq;
        }
    }

    //cout << "-> " << sides << '\n';

    vll zs;
    if(odd)
        for(auto [k, v] : hs)
            if(v>0&& v%2)
                zs.eb(k);
    ll zsize = zs.size();
    sort(all(zs));

    /* for(auto z : zs) cout << z << ' ';
    cout << '\n'; */

    if(odd>=2)
    {
        ll num = 0;
        ll l, r;
        for(ll i = zsize-2; i >= 0; i--)
        {
            l = zs[i], r = zs[i+1];
            if(r-l < sum)
            {
                top = l;
                bottom = r;
                break;
            }
        }
        if(bottom) lines += 2;
    }

    if(odd && !top && !bottom)
    {
        ll num = 0;
        for(ll i = zsize-1; i >= 0; i--)
        {
            if(zs[i] < sum)
            {
                num = zs[i];
                break;
            }
        }
        top = num;
        if(top) lines++;
    }

    if(lines > 2)
        cout << top + bottom + sides << '\n';
    else
        cout << 0 << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
