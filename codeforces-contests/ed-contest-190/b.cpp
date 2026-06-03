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
    string s; cin >> s;
    ll cnt = 0;
    string t = "";

    ll odd = 0;
    for(auto x : s) 
    {
        if(x=='4')
            ++cnt;
        else t += x;

        if(x=='1' || x=='3')
            ++odd;
    }

    ll size = 0, ans = 0, even = 0;
    for(auto x : t)
    {
        if(x=='2')
            ++even;
        size = max(size, even+odd);
        if(x=='1' || x=='3')
            --odd;
    }

    cout << s.length() - size << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
