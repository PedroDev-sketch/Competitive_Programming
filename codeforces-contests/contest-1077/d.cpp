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
    ll x, y; cin >> x >> y;

    bitset<32> btx(x), bty(y);
    //cout << "btx-> " << btx << "\nbty-> " << bty << '\n';

    ll msbx = 31, msby = 31;
    for(; msbx>=0 && btx[msbx]==0; --msbx);
    for(; msby>=0 && bty[msby]==0; --msby);

    ll q = 0;
    for(ll i = 31; i >= 0; --i)
        if(!btx[i])
        {
            ll add = (1LL << i);
            if(abs(y - (q+add)) < abs(y - q))
                q += add;
        }
    ll ansq = abs(y - q);

    ll p = 0;
    for(ll i = 31; i >= 0; --i)
        if(!bty[i])
        {
            ll add = (1LL << i);
            if(abs(x - (p+add)) < abs(x - p))
                p += add;
        }
    ll ansp = (x - p);

   /*  bitset<32> btp(p), btq(q);
    cout << "btp-> " << btp << "\nbtq-> " << btq << '\n'; */

    if(ansq < ansp)
        cout << x << " " << q << '\n';
    else
        cout << p << " " << y << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
