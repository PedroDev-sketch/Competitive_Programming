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
    ll x, y, diff; cin >> x >> y;

    bitset<32> btx(x), bty(y);
    //cout << "btx-> " << btx << "\nbty-> " << bty << '\n';

    ll msb = 31;
    for(; msb>=0 && (btx[msb]!=bty[msb] || !btx[msb]); --msb);

    if(msb==-1)
    {
        cout << x << " " << y << '\n';
        return;
    }

    bitset<32> btp = btx, btq = bty;
    btq[msb] = 0;
    for(ll i = msb-1; i >= 0; --i)
    {
        btp[i] = 0;
        btq[i] = 1;
    }

    ll p = btp.to_ullong(), q = btq.to_ullong();
    cout << p << " " << q << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
