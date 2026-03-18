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
    vll xs(n); 
    vll odd, even;
    for(auto& x : xs) 
    {
        cin >> x;
        if(x%2) odd.eb(x);
        else even.eb(x);
    }

    if(xs[0] == 1 && xs.back() != 1)
    {
        cout << 1 << ' ' << xs.back() << '\n';
        return;
    }

    if(even.size() > 1)
    {
        ll num = even[0];
        ll num2 = even.back();
        if(num!=num2)
        {
            cout << num<< ' ' << num2 << '\n';
            return;
        }
    }


    if(odd.size() > 1)
    {
        ll lodd = -1;
        for(auto x : odd)
        {
            if(lodd != -1 && x < 2LL*lodd)
            {
                cout << lodd << ' ' << x << '\n';
                return;
            }
            lodd = x;
        }
    }

    for(ll i = 0; i < n; i++)
    {
        for(ll j = i+1; j < n; j++)
        {
            if((xs[j]%xs[i])%2==0)
            {
                cout << xs[i] << ' ' << xs[j] << '\n';
                return;
            }
        }
    }

    cout << "-1\n";
    return;
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}



