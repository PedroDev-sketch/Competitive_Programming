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

ll kadane_max(const vll& arr) 
{
    if (arr.empty()) return 0;
    ll fmax = arr[0];
    ll currmax = arr[0];
    rep(i, 1, arr.size()) 
    {
        currmax = max(arr[i], currmax + arr[i]);
        fmax = max(fmax, currmax);
    }
    return fmax;
}

ll kadane_min(const vll& arr) 
{
    if (arr.empty()) return 0;
    ll fmin = arr[0];
    ll currmin = arr[0];
    rep(i, 1, arr.size()) 
    {
        currmin = min(arr[i], currmin + arr[i]);
        fmin = min(fmin, currmin);
    }
    return fmin;
}


void solve()
{
    ll n, m; cin >> n >> m;

    map<ll, ll> hs;
    ll sum = 0;

    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        sum += x;
        hs[x] += x;
    }

    vpll ys;
    for(auto h : hs) ys.eb(h);

    ll size = ys.size();
    if(size == m || size == 0)
    {
        cout << 0 << '\n';
        return;
    }

    ll breakpoint= 0;
    rep(i, 0, size)
    {
        if(ys[(i+1)%size].ff != (ys[i].ff + 1) % m)
        {
            breakpoint= i; 
            break;
        }
    }
    
    vll linear_sums(size);
    ll totalsum = 0;
    
    rep(i, 0, size)
    {
        int j = (breakpoint+ 1 + i) % size;
        linear_sums[i] = ys[j].ss;
        totalsum += ys[j].ss;
    }

    ll maxsum = kadane_max(linear_sums);
    ll minsum = kadane_min(linear_sums);
    ll wrapsum = totalsum - minsum;

    ll removesum = max(maxsum, wrapsum);
    cout << (sum - removesum) << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}