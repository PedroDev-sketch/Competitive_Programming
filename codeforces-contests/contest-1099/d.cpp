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
    string s; cin >> s;
    vll a(n), c(n);
    for(auto& x : a) cin >> x; 
    for(auto& x : c) cin >> x;

    for (ll i = 1; i < n; ++i) 
    {
        if (c[i] < c[i - 1]) 
        {
            cout << "No\n";
            return;
        }
    }

    vll b(n), mx(n);
    mx[n-1] = c[n-1];
    for(ll i = n-2; i >= 0; --i)
    {
        mx[i] = c[i];
        if(s[i+1]=='1')
            mx[i] = min(mx[i], mx[i+1] - a[i+1]);
    }

    if (s[0] == '1' && a[0] != c[0]) 
    {
        cout << "No\n";
        return;
    }
    
    b[0] = a[0] = c[0];
    for(ll i = 1; i < n; ++i)
    {
        b[i] = (s[i]=='1') ? (b[i-1] + a[i]) : mx[i];
        a[i] = b[i] - b[i-1];
    }

    for(ll i = 0; i < n; ++i)
    {
        if(b[i] > c[i])
        {
            cout << "No\n";
            return;
        }
        if(i>0 && c[i]>c[i-1] && b[i] != c[i])
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for(auto x : a) cout << x << ' ';
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
