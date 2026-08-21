#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

void solve()
{
    ll n, k, r = 0, b = 0; cin >> n >> k;
    n<<=1;
    string s; cin >> s;
    for(ll i = 0; i < n; ++i)
    {
        if(s[i]=='1')
        {
            if(s[(i+1)%n]=='0')
            {
                if(i&1)
                    ++b;
                else ++r;
            }
            else
            {
                if(i&1)
                    ++r;
                else ++b;
            }
        }
    }

    cout << r << " " << b << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
