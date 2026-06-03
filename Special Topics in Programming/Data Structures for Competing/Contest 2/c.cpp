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

void backtrack(set<string>& ys, string s, ll size, ll max_size)
{
    if(size==max_size)
    {
        ys.insert(s);
        return;
    }

    if(s[size] == '1')
    {
        string news = s;
        news[size] = '0';
        backtrack(ys, news, size+1, max_size);
    }
    backtrack(ys, s, size+1, max_size);
}

void solve()
{
    ll n; cin >> n;
    set<ll> xs;
    xs.insert(n);

    string s = "";
    ll test = 0;
    for(ll i = 0; i < 61 && ((ll)1 << i) <= n; i++)
    {
        if(n & (ll)1 << i)
        {
            s = '1'+s;
        }
        else s='0'+s;
    }

    set<string> ys;
    ys.insert(s);
    ll size = s.size();
    backtrack(ys, s, 0, size);
    //cout << s << '\n';
    for(auto y : ys)
    {
        //cout << "bin-> " << y << '\n';
        ll num = 0;
        for(ll i = 0; i < size; i++)
        {
            if(y[i]=='1') {num += ((ll)1<<(size-i-(ll)1)); /* cout << "op-> " << ((ll)1<<(size-i-1)) << " " << (size-i-1) << '\n'; */}
        }
        xs.insert(num);
        //cout << "num-> " << num << '\n';
    }

    for(auto x : xs) cout << x << '\n';
}

signed main()
{
    //fio;
    ll t = 1; //cin >> t;
    while(t--) solve();
}
