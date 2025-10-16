#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define MAXN (1e9 + 7)
#define ff first 
#define ss second 

void solve()
{
    ll n, k; cin >> n >> k;
    
    ll c = n*n;
    ll left = c - k;
    if(k == c-1)
    {
        cout << "NO\n";
        return;
    }
    char xs[n][n];

    ll idx = 0, idy = 0;
    while(idx < n)
    {
        if(k)
        {
            xs[idx][idy] = 'U';
            k--;
        }
        else
        {
            if(idx < n-1)
            {
                xs[idx][idy] = 'D';
            }
            else
            {
                if(idy==0 || (idy-1 >= 0 && xs[idx][idy-1] == 'U')) xs[idx][idy] = 'R';
                else xs[idx][idy] = 'L';
            }
        }

        idy++;
        if(idy==n)
        {
            idy = 0;
            idx++;
        }
    }

    cout << "YES\n";
    for(ll i = 0; i < n; i++)
    {
        for(auto j = 0; j < n; j++)
            cout << xs[i][j];
        cout << '\n';
    }

}

signed main()
{
    fio;
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}
