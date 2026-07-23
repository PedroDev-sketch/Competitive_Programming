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

    ll block = 1, seq = 0, mxseq = 1;
    char last = s[0];
    for(char x : s)
    {
        if(x==last)
            ++seq;
        else
        {
            ++block;
            last = x;
            mxseq = max(mxseq, seq);
            seq = 1;
        }
    }
    mxseq = max(mxseq, seq);

    if(s[0] != s.back() && mxseq > 1)
        ++block;
    cout << block << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
