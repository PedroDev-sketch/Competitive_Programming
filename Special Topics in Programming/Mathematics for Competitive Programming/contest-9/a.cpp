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
    string s, t; cin >> s >> t; 

    ll red_adv = 0;
    for(ll i = 0; i < n; ++i)
    {
        ll red = s[i]-'0', blue = t[i] - '0';
        if(red > blue)
            red_adv++;
        else if(blue > red)
            red_adv--;
    }

    if(!red_adv) cout << "EQUAL" << '\n';
    else cout << (red_adv < 0 ? "BLUE" : "RED") << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
