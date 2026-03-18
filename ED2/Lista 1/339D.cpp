#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define fio cin.tie(0)->ios::sync_with_stdio(0)

using Op = ll(*) (ll, ll);
Op op, prox;

//Xenia and Bit Operations
class SegTree
{
    ll N; vll ns;
public:
    SegTree(const vll& xs) : N(xs.size()), ns(4*N, 0)
    {
        for(ll i = 0; i < N; i++)
            update(i, xs[i]);
    }

    void update(ll i, ll value)
    {
        op = [](ll x, ll y) { return x | y; };
        prox = [](ll x, ll y) { return x ^ y; };
        update(1, 0, N-1, i, value);
    }

private:
    void update(ll node, ll L, ll R, ll i, ll value)
    {
        if(i < L || i > R)
            return;

        if(L==R)
        {
            ns[node] = value;
            return;
        }

        update(2*node, L, (L+R)/2, i, value);
        update(2*node+1, (L+R)/2+1, R, i, value);

        ns[node] = op(ns[2*node], ns[2*node + 1]);
        swap(op, prox);
    }

public:
    void v()
    {
        cout << ns[1] << '\n';
    }

    void debug()
    {
        cout << "-> ";
        for(auto n : ns)
        {
            cout << n << ' ';
        }
        cout << '\n';
    }
};

signed main()
{
    fio;

    ll n, m; cin >> n >> m;
    n = 1LL<<n;
    vll xs(n); for(auto& x : xs) cin >> x;

    SegTree tree(xs);
    while(m--)
    {
        ll p, b; cin >> p >> b;
        tree.update(p-1, b);
        tree.v();
    }
}



