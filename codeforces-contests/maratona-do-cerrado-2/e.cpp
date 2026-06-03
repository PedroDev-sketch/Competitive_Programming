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

constexpr ll MAX = 1e7+7;

vll spf(MAX+3, 0);

void sieve(ll num=MAX)
{
    for(ll i = 2; i <= num; ++i) spf[i] = i;
    for(ll i = 2; i*i <= num; ++i)
        if(spf[i]==i)
            for(ll j = i*i; j <= num; j += i)
                if(spf[j]==j) spf[j] = i;
}

void solve()
{
    ll n, a = 0; cin >> n;
    vll xs(n), score(MAX+3); 
    for(auto& x : xs)
    { 
        cin >> x;
        while(x > 1)
        {
            ll pt = spf[x];
            score[pt] += pt;
            x /= pt;  
        }
    }

    sort(all(score), greater<>());
    for(ll i = 0; i < MAX+3; i+=2)
        a += score[i];

    cout << a << '\n';
}

signed main()
{
    fio;
    sieve();
    solve();
}
