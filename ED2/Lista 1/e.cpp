#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vcc vector<char>

class SegTree
{
    ll N;
    vll ns;
public:
    SegTree(const string& s) : N((ll)s.size()), ns(4*N, 0)
    {
        build(1, 0, N-1, s);
    }

    void update(ll i, char val)
    {
        ll mask = (1LL << (val - 'a'));
        update(1, 0, N-1, i, mask);
    }

    ll RSQ(ll a, ll b)
    {
        ll mask = RSQ(1, 0, N-1, a, b);
        return __builtin_popcount(mask);
    }

private:
    void build(ll node, ll L, ll R, const string& s)
    {
        if(L==R)
        {
            ns[node] = (1LL << (s[L] - 'a'));
            return;
        }

        ll mid = (L+R)/2;
        build(2*node, L, mid, s);
        build(2*node + 1, mid+1, R, s);
        ns[node] = ns[2*node] | ns[2*node+1];
    }

    void update(ll node, ll L, ll R, ll i, ll value)
    {
        if(L==R)
        {
            ns[node] = value;
            return;
        }

        ll mid = (L+R)/2;

        if(i <= mid)
            update(2*node, L, mid, i, value);
        else
            update(2*node+1, mid+1, R, i, value);

        ns[node] = ns[2*node] | ns[2*node+1];
    }

    ll RSQ(ll node, ll L, ll R, ll a, ll b)
    {
        if(a > R || b < L)
            return 0;
        
        if(a <= L && R <= b)
            return ns[node];
        
        ll mid = (L+R)/2;
        ll x = RSQ(2*node, L, mid, a, b);
        ll y = RSQ(2*node + 1, mid+1, R, a, b);
        return x|y;
    }
};

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    string s; cin >> s;
    SegTree st(s);

    ll q; cin >> q;
    while(q--)
    {
        ll type; cin >> type;
        if(type==1)
        {
            ll pos; char c;
            cin >> pos >> c;
            st.update(pos-1, c);
        } 
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << st.RSQ(l-1, r-1) <<'\n';
        }
    }
}
