//The Seals of Shanghai

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define fio cin.tie(0)->ios::sync_with_stdio(0);
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

/**
 *  @return  Unordered vector with all divisors of x.
 *  Time complexity: O(sqrt(N))
*/
vll divisors(ll x) {
    vll ds;
    for (ll i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            ds.eb(i);
            if (i * i != x) ds.eb(x / i);
        }
    return ds;
}

void special_case(int n)
{
    cout << n << " " << 1'000'000'000 - 1 << '\n';
}

signed main()
{
    ll n;
    cin >> n;

    if(n == 1) {special_case(1); return 0;}

    vll xs(n);
    for(auto& x : xs) cin >> x;

    sort(all(xs));

    vll ys;
    for(int i = 1; i < n; i++) ys.eb(xs[i] - xs[i-1]);

    ll g = ys[0];
    for(int i = 1; i < n-1; i++) g = gcd(g, ys[i]);

    if(g > 1)
    {
        vll divs = divisors(g);

        ll ans = divs.size()-1;
        cout << 1 << " " << ans << '\n';
    }

    else if(g)
    {
        set<ll> zs;
        for(auto x : xs) zs.insert(x);
        if(zs.size() <= 2) {special_case(2); return 0;} 

        ll n1 = xs[0], n2 = xs[n/2], n3 = xs[n-1];
        ll d1 = n2 - n1, d2 = n3 - n2, d3 = n3 - n1;

        vll divs1 = divisors(d1);
        vll divs2 = divisors(d2);
        vll divs3 = divisors(d3);

        set<ll> buffer;
        buffer.insert(all(divs1)); 
        buffer.insert(all(divs2));      
        buffer.insert(all(divs3)); 

        set<ll> ans;
        for(auto b : buffer)
        {
            set<ll> groups;
            for(auto x : xs)
            {
                groups.insert(x%b);
            }

            if(groups.size() == 2) ans.insert(b);
        }

        cout << 2 << " " << ans.size() << '\n';
    }

    else special_case(1);
    
    return 0;
}