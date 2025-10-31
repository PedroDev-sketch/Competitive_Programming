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
    bool ans = true;
    map<string, ll> hs;
    while(n--)
    {
        string s; cin >> s;

        char a = s[0], b = s[1];
        if(hs[s]) ans = false;
        hs[s]++;
        if(a!='H' && a!='D' && a!='C' && a!='S') ans = false;
        if(b != 'A' && b != '2' && b != '3' 
            && b != '4' && b != '5' && b != '6' &&
            b != '7' && b != '8' && b != '9' &&
            b != 'T' && b != 'J' && b != 'K' && b != 'Q') ans = false;
    }
    cout << (ans ? "Yes" : "No") << '\n'; 
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
