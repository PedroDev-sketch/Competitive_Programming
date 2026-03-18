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
    vll odd, even;
    vll xs(n); 
    for(auto& x : xs) 
    {
        cin >> x;
        if(x&1) odd.eb(x);
        else even.eb(x); 
    }

    //cout << "debug1\n";

    sort(all(odd), greater<>()); sort(all(even), greater<>());

    if(odd.empty())
    {
        for(ll i = 0; i < n; i++)
            cout << "0 ";
        cout <<'\n';
        return;
    }

    //cout << "debug2\n";

    if(even.empty())
    {
        for(ll i = 0; i < n; i++)
        {
            if(i&1)
                cout << 0 << " ";
            else
                cout << odd[0] << ' ';
        }
        cout << '\n';  
        return; 
    }

    //cout << "debug3\n";

    ll k = 2, neven = 0, nodd = odd[0];
    cout << nodd << " ";
    for(auto& e : even)
    {
        neven += e;
        cout << nodd + neven << " ";
        k++;
    }

    //cout << "debug4\n";

    for(; k <= n; k++)
    {
        ll left = k - even.size() - 1, num = nodd+neven;
        if(left&1)
            num -= even.back();
        left+=left&1;
        if(odd.size() - 1 < left)
        {
            cout << "0 ";
            continue;
        }
        cout << num << " ";
    }
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
