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

constexpr ll MOD = 998244353LL;

ll add(ll a, ll b)
{
    a %= MOD; b %= MOD;
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a - b + MOD) % MOD;
}

ll multiply(ll a, ll b)
{
    a %= MOD; b %= MOD;
    return (a*b)%MOD;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
            res = multiply(res, a);
        a = multiply(a, a);
        b >>= 1LL;
    }
    return res;
}

ll divide(ll a, ll b)
{
    ll inv = binpow(b, MOD-2);
    a %= MOD;
    return (a*inv)%MOD;
}

vvll matmult(const vvll& a, const vvll& b)
{
    ll l1 = a.size(), c1 = a[0].size();
    ll l2 = b.size(), c2 = b[0].size();

    vvll res(l1, vll(c2, 0));
    rep(i, 0, l1)
        rep(j, 0, c2)
            rep(k, 0, c1)
                res[i][j] = add(res[i][j], multiply(a[i][k], b[k][j]));
    return res;
}

vvll matpow(vvll a, ll b) {
    vvll res={{1, 0}, {0, 1}};
    while(b) {
        if(b & 1)
            res = matmult(res, a);
        a = matmult(a, a);
        b >>= 1LL;
    }

    return res;
}

void solve()
{
    ll a, b, n, m, vn, vm; cin >> a >> b >> n >> m >> vn >> vm;

    vvll mat1 = {{0, 1}, {b, a}};
    mat1 = matpow(mat1, n);

    vvll mat2 = {{0, 1}, {b, a}};
    mat2 = matpow(mat2, m);

    ll x1 = mat2[0][0], y1 = mat2[0][1];
    ll x2 = mat1[0][0], y2 = mat1[0][1];

    ll det    = sub(multiply(x1, y2), multiply(x2, y1));
    ll det_f0 = sub(multiply(vm, y2), multiply(vn, y1));
    ll det_f1 = sub(multiply(x1, vn), multiply(x2, vm));

    ll f0 = divide(det_f0, det);
    ll f1 = divide(det_f1, det);
    cout << f0 << " " << f1 << '\n';
}

signed main()
{
    fio;
    ll t=1;
    cin >> t;
    while(t--)
        solve();
}
