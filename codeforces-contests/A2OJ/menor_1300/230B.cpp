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

vll sieve(ll num = 1e6 + 7)
{
    vll primes(num+1, 0);
    for(ll i = 2; i <= num; i++)
    {
        if(!primes[i]) primes[i]=1;
        for(ll j = i; j <= num; j+=i)
            if(!primes[j])
                primes[j] = 2;
    }

    return primes;
}

signed main()
{
    fio;
    
    ll n; cin >> n;
    vll xs(n); for(auto& x : xs) cin >> x;
    vll ps = sieve();

    ll i = 0;
    //for(auto p : ps) {cout << i++ << " -> " << p << '\n'; if(i>100)break;}
    for(auto x : xs)
    {
        ll sq = sqrt(x);
        if(sq*sq==x && ps[sq]==1) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    
    return 0;
}