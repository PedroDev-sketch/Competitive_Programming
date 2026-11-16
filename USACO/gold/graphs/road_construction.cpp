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
ll MAX_SIZE = 1;

class DSU
{
    private:
        vector<ll> parents;
        vector<ll> sizes;

    public:
        DSU(ll size) : parents(size), sizes(size, 1)
        {
            for(ll i = 0; i < size; ++i)  parents[i] = i;
        }

        ll find(ll x) { return parents[x]==x ? x : (parents[x] = find(parents[x])); }

        bool unite(ll x, ll y)
        {
            ll x_root = find(x);
            ll y_root = find(y);
            if(x_root == y_root) 
                return false;
            if(sizes[x_root] < sizes[y_root])
                swap(x_root, y_root);
            sizes[x_root] += sizes[y_root];
            MAX_SIZE = max(MAX_SIZE, sizes[x_root]);
            parents[y_root] = x_root;
            return true;
        }

        bool connected(ll x, ll y) { return find(x)==find(y); }
};

void solve()
{
    ll n, m; cin >> n >> m;
    
    ll num = n;
    DSU dsu(n+1);
    while(m--)
    {
        ll a, b; cin >> a >> b;
        if(!dsu.connected(a, b))
        {
            dsu.unite(a, b);
            num--;
        }
        
        cout << num << ' ' << MAX_SIZE << '\n';
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
