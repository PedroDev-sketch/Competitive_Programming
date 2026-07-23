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
    vll hs(n), ws(n); for(auto& x : hs) cin >> x;

    for(ll i = 0; i < n; ++i)
    {
        vll unrolled(n+1);
        for(ll j = 1; j <= n; ++j)
            unrolled[j] = hs[(i+j-1)%n];

        vll suffix(n+1, 0);
        suffix[1] = unrolled[1];
        for(ll j = 2; j < n; ++j)
            suffix[j] = max(suffix[j-1], unrolled[j]);

        vll prefix(n+1, 0);
        prefix[n] = unrolled[n];
        for(ll j = n-1; j >= 2; --j)
            prefix[j] = max(prefix[j+1], unrolled[j]);

        ll sum = 0;
        for(ll j = 2; j <= n; ++j)
            sum += min(prefix[j], suffix[j-1]);
        ws[i] = sum;
    }

    for(auto w : ws) cout << w << ' ';
    cout << '\n';
}

signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}