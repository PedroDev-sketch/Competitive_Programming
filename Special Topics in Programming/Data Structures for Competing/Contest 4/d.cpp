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
    ll n, m; cin >> n >> m;

    map<ll, ll> hs;
    ll sum = 0;

    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        sum += x;
        hs[x] += x;
    }

    ll ans = sum;

    vpll ys;
    for(auto h : hs) ys.eb(h);
    ll size = ys.size();

    if(size==m)
    {
        cout << 0 << '\n';
        return;
    }

    ll break_point = 0;
    rep(i, 0, size)
    {
        if(ys[(i+1)%size].ff != ( (ys[i].ff+1) % m ))
        {
            break_point = i;
            break;
        }
    }

    vll sums(size);
    rep(i, 0, size)
    {
        ll k = (break_point - i + size)%size;
        sums[k] = sum;

        if(ys[(k+1)%size].ff == (ys[k].ff+1)%m)
            sums[k] = sums[(k+1)%size];
        sums[k] -= ys[k].ss;
    }

    /* ll it = ys[0].ff;
    ll idx = 0;
    queue<ll> qs;
    qs.push(it);
    */
    /* for(auto y : ys)
    {
        cout << "ys : " << y.ff << ' ' << y.ss << '\n';
    } */

    /* while(!qs.empty())
    {
        idx++;
        ll st = qs.front(); qs.pop();

        //cout << "-> " << st << '\n';
        //cout << "comp -> " << (ys[idx].ff % m) << ' ' << ((ys[idx-1].ff + 1) % m) << '\n';

        ll buff = hs[st];
        while( (ys[idx].ff) == ( (ys[idx-1].ff + 1) % m ) && idx < n )
        {
            buff += ys[idx].ss;
            idx++;
        }
        if(idx < ys.size())
        {
            qs.push(ys[idx].ff);
        }

        //cout << "buff: " << buff << '\n';

        ans = min(ans, sum - buff);
    } */

    ans = *min_element(all(sums));
    cout << ans << '\n';
}

signed main()
{
    //fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
