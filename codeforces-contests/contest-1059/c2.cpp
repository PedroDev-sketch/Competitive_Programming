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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll a, b;
    cin >> a >> b;

    ll op = 0;
    vll xs;
    string sa = "", sb = "";

    ll maxnum = max(a, b);
    for (ll i = 0; i < 64 && (1LL << i) <= maxnum; i++)
    {
        if ((1LL << i) & a)
            sa = '1' + sa;
        else
            sa = '0' + sa;

        if ((1LL << i) & b)
            sb = '1' + sb;
        else
            sb = '0' + sb;
    }

    ll size = sa.size();
    ll a1 = -1;
    for (ll i = 0; i < size; i++)
    {
        if (sa[i] == '1')
        {
            a1 = i;
            break;
        }

        if (sb[i] == '1' && a1 == -1)
        {
            cout << "-1\n";
            return;
        }
    }
    // cout << sa << '\n' << sb << '\n';

    string x = "";
    ll numx = 0;
    for (ll i = a1 + 1; i < size; i++)
    {
        char ca;
        if (sa[i] != sb[i])
        {
            if (sb[i] == '1')
                ca = '1';
            else
                ca = sa[i];

            x = ca + x;
            if (ca == '1')
                numx += (1LL << (size - i - 1));
        }
        else
        {
            ca = '0';
            x = ca + x;
        }
    }

    if(numx) xs.eb(numx);
    a = (a xor numx);
    //cout << "-> " << numx << '\n';
    if(sb[a1]=='0')
    {
        numx = (1LL<<(size-a1-1));
        a = (a xor numx);
        xs.eb(numx);
        //cout << "-> " << numx << '\n';
    }

    /* while(op++ < 100)
    {
        if(a==b) break;
        ll num = (a xor b);

        if(num > a)
        {

        }

        a = (a xor num);
    } */

    if (a != b)
        cout << "-1\n";
    else
    {
        cout << xs.size() << '\n';
        for (auto x : xs)
            cout << x << ' ';
        cout << '\n';
    }
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
