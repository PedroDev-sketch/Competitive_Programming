#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

class DSU
{
    private:
        vll sizes, parents;
    public:
        DSU(ll n) : parents(n+1), sizes(n, 1)
        {
            for(ll i = 0; i < n; ++i)
                parents[i] = i;
        }

        ll find(ll x)
        {
            return (parents[x]==x ? x : (parents[x] = find(parents[x])));
        }

        bool unite(ll x, ll y)
        {
            ll rootx = find(x), rooty = find(y);
            if(rootx==rooty)
                return false;

            if(sizes[rootx] < sizes[rooty])
                swap(rootx, rooty);
            
            sizes[rootx] += sizes[rooty];
            parents[rooty] = rootx;
            return true;
        }

        bool connected(ll x, ll y)
        {
            return find(x)==find(y);
        }
};

void solve()
{
    ll n, a, b, idx = 0; cin >> n >> a >> b;
    map<ll, ll> hs;
    vll xs(n); for(auto& x : xs) {cin >> x; hs[x] = idx; ++idx;};
    DSU dsu(n+2);

    ll root_a = n, root_b = n+1;

    for(auto x : xs)
    {
        if(hs.count(a-x))
            dsu.unite(hs[x], hs[a-x]);
        else
            dsu.unite(hs[x], root_b);
        
        if(hs.count(b-x))
            dsu.unite(hs[x], hs[b-x]);
        else
            dsu.unite(hs[x], root_a);
    }

    if(dsu.connected(root_a, root_b))
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(auto x : xs)
    {
        if(dsu.connected(hs[x], root_a))
            cout << 0;
        else cout << 1;
        cout << ' ';
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
