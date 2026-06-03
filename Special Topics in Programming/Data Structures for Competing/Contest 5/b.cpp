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
    string h, m; cin >> h >> m;
    ll hnum = stoi(h), mnum = stoi(m);
    while(true)
    {
        ll a = hnum/10, b = hnum%10, c = mnum/10, d = mnum%10;
        ll hr = a*10 + c, mi = b*10 + d; 
        if(hr <= 23 && hr >= 0 && mi <= 59 && mi >= 0)
        {
            cout << a*10 + b << " " << c*10 + d << '\n'; 
            return;
        }
        
        mnum++; 
        if(mnum == 60){mnum = 0; hnum++;}
        if(hnum==24) hnum = 0;
    }
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
