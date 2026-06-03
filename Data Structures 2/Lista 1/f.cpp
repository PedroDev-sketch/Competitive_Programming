#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

class SegTree
{
    ll N;
    vll ns, lazy;
public:
    SegTree(const vll& xs) : N((ll)xs.size()), ns(4*N, 0), lazy(4*N, 0)
    {
        for(size_t i = 0; i < N; i++)
            update(i, i, xs[i]);
    }

    void update(ll a, ll b, ll value)
    {
        update(1, 0, N-1, a, b, value);
    }

    void run_through()
    {
        for(auto n : ns) cout << n << ' ';
        cout << '\n';
    }

private:
    void update(ll node, ll L, ll R, ll a, ll b, ll value)
    {
        if(lazy[node])
        {
            ns[node] = lazy[node];

            if(L < R)
            {
                lazy[2*node] = lazy[node];
                lazy[2*node + 1] = lazy[node];
            }

            lazy[node] = 0;
        }

        if(a > R || b < L)
            return;

        if(a <= L && b >= R)
        {
            ns[node] = value;

            if(L < R)
            {
                lazy[2*node] = ns[node];
                lazy[2*node+1] = ns[node];
            }

            return;
        }

        ll mid = (L+R)/2;
        update(2*node, L, mid, a, b, value);
        update(2*node+1, mid+1, R, a, b, value);
        ll lowermax = max(ns[2*node], ns[2*node+1]);
        ns[node] = max(ns[node], lowermax);
    }

public:
    ll RSQ(ll a, ll b)
    {
        return RSQ(1, 0, N-1, a, b);
    }

private:
    ll RSQ(ll node, ll L, ll R, ll a, ll b)
    {
        if(lazy[node])
        {
            ns[node] = lazy[node];

            if(L < R)
            {
                lazy[2*node] = lazy[node];
                lazy[2*node + 1] = lazy[node];
            }

            lazy[node] = 0;
        }

        if(a > R || b < L)
            return 0;

        if(a <= L && b >= R)
            return ns[node];

        ll mid = (L+R)/2;
        ll x = RSQ(2*node, L, mid, a, b);
        ll y = RSQ(2*node+1, mid+1, R, a, b);
        return max(x, y);
    }
};

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    ll n; cin >> n;
    vll a(n); for(auto& x : a) cin >> x;
    ll m; cin >> m;

    SegTree st(a);
    while(m--)
    {
        ll w, h; cin >> w >> h;
        ll curr_max = st.RSQ(0, w-1);
        cout << curr_max << '\n';
        st.update(0, w-1, curr_max + h);
    }
}