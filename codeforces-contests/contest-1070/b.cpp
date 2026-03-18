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
    ll n, ans = 0; cin >> n;
    string s; cin >> s;

    ll front, back, bc = 0;
    for(front = 0; front < n && s[front] == '0'; front++);
    for(back = n-1; back >= 0 && s[back] == '0' && back > front; back--, bc++);

    ans = max(ans, bc + front);

    ll seq = 0;
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == '0')
            seq++;
        else
        {
            ans = max(ans, seq);
            seq = 0;
        }
    }
    ans = max(ans, seq);
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
