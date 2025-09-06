#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()

/**
 *  @return  Vectors with primes from [1, n] and smallest prime factors.
 *  Time complexity: O(Nlog(log(N)))
*/
pair<vll, vll> sieve(ll n) {
    vll ps, spf(n + 1);
    rep(i, 2, n + 1) if (!spf[i]) {
        ps.eb(i);
        for (ll j = i; j <= n; j += i)
            if (!spf[j]) spf[j] = i;
    }
    return { ps, spf };
}

signed main()
{
    int n, m;
    cin >> n >> m;

    auto [xs, ys] = sieve(m);
    auto it = lower_bound(all(xs), n);

    if(*it == n && ((it - xs.begin() + 1) <= m && xs[it - xs.begin() + 1] == m))
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}