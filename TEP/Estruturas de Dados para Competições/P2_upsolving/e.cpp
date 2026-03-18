#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpll vector<pll>
#define ff first 
#define ss second 

vll primes(1e6+100'001, 0);

class SegTree
{
private:
    ll N;
    vpll ts;
public:
    SegTree(ll n) : N(n), ts(4*n, {0, 0}) {}
    pll query(ll ql, ll qr)
    {
        return query_range(ql, qr, 0, N-1, 1);
    }
    void update(ll i, ll v)
    {
        return update_range(i, v, 0, N-1, 1);
    }
    void check()
    {
        for(auto t : ts)
            cout <<"-> (" << t.ff << ", " << t.ss << ")\n";
    }
private:
    pll query_range(ll ql, ll qr, ll l, ll r, ll no)
    {
        if(l >= ql && r <= qr) return ts[no];
        if(l > qr || r < ql) return {0, 0};

        ll mid = (l+r)/2;
        pll esq = query_range(ql, qr, l, mid, 2*no);
        pll dir = query_range(ql, qr, mid+1,  r, 2*no+1);
        return merge(esq, dir);
    }
    void update_range(ll i, ll v, ll l, ll r, ll no)
    {
        if(l==r)
        {
            ts[no].ff += v;
            ts[no].ss = i;
            return;
        }
        
        ll mid = (l+r)/2;
        if(i <= mid) update_range(i, v, l, mid, 2*no);
        else update_range(i, v, mid+1, r, 2*no+1);
        ts[no] = merge(ts[2*no], ts[2*no+1]);
    }
    pll merge(pll a, pll b)
    {
        if(primes[a.ff]==primes[b.ff])
        {
            if(a.ff >= b.ff)
                return a;
            return b;
        }
        if(primes[a.ff] > primes[b.ff])
            return a;
        return b;
    }
};

void sieve(ll num = 1e6+100'000)
{
    for(ll i = 2; i <= num; i++)
    {
        if(primes[i])
            continue;
        for(ll j = i; j <= num; j+=i)
            primes[j]++;        
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    sieve();
    ll n; cin >> n;

    SegTree seg(n);
    for(ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        seg.update(i, x);
    }

    ll m; cin >> m;
    ll idx = 1;
    while(m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t==1)
            seg.update(x-1, y);
        else
        {
            pll ret = seg.query(x-1, y-1);
            cout << "#" << idx << ": " << ret.ss+1 << " " << ret.ff << " " << primes[ret.ff] << '\n';
            idx++;
        }
    }
}
