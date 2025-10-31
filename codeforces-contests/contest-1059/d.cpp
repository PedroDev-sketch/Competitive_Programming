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
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second

void bin_search(ll l, ll r, ll limit, ll& f_index)
{
    //cout << "-> " << l << " " << r << '\n' << flush;
    if(l==r) {f_index = l; return;}
    if(limit == 40) return;
    ll m = l + (r-l)/2;

    ll fp, fa;
    cout << 1 << " " << l << " " << m << '\n' << flush;
    cin >> fp;
    cout << 2 << " " << l << " " << m << '\n' << flush;
    cin >> fa;

    ll fnum = fa - fp;

    if(fnum>0) 
        bin_search(l, m, limit+1, f_index);
    else
        bin_search(m+1, r, limit+1, f_index); 
}

ll find_size(ll n)
{
    ll a;
    cout << 1 << " " << 1 << " " << n << '\n' << flush;
    cin >> a;

    ll b;
    cout << 2 << " " << 1 << " " << n << '\n' << flush;
    cin >> b;

    ll size = b - a;
    return size;
}

void solve()
{
    ll n; cin >> n;

    ll l = 1, r = n;
    pll ans;

    ll size = find_size(n), f_idx = 0;
    bin_search(l, r, 0, f_idx);

    ans = mp(f_idx, f_idx+size-1);
    cout << "! " << ans.ff << " " << ans.ss << '\n' << flush;
}

signed main()
{
    fio;
    ll t = 1; cin >> t;
    while(t--) solve();
}
