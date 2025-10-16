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

signed main()
{
    fio;
    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = 0;
    vll xs(n); for(auto& x : xs) {cin >> x; sum += x;}

    ll fhole = xs[0];
    ll curr = (fhole * a)/sum;
    ll rem = (fhole*a)%sum;
    ll rm = 0;
    sort(all(xs), greater<>());
    bool flag = false;
    for(ll i = 0; i < n && curr < b; i++)
    {
        if(xs[i] == fhole && !flag)
        {
            flag = true;
            continue;
        }
        curr *= sum;
        curr += rem;
        sum -= xs[i];
        rem = curr%sum;
        curr /= sum;
        rm++;
    }
    cout << rm << '\n';

    return 0;
}
