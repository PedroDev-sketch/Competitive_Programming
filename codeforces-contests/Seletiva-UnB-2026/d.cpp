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

ll f(char x)
{
    if(x >= '0' && x <= '9')
        return (x-'0');
    return (x-'a')+10;
}

void solve()
{
    ll n, b, ptr = 7, bin_key = 0, cnt = 0; cin >> n >> b;
    string hex; cin >> hex;
    vector<string> bin;

    for(ll i = 1; i < hex.size(); i+=2)
    {
        ll num = f(hex[i-1])*16 + f(hex[i]);
        bitset<8> bt(num);
        bin.push_back(bt.to_string());
    }
    
    /* for(auto x : bin)
        cout << x << '\n'; */

    auto unpack = [&](ll num)
    {
        if(bin_key >= bin.size())
            return (ll)-7;

        ll pow = 1, ans = 0;

        for(ll i = 0; i < num; ++i)
        {
            if(bin[bin_key][ptr]=='1')
                ans += pow;
            ptr--;
            if(ptr < 0)
            {
                ptr = 7;
                ++bin_key;
                if(bin_key >= bin.size() && i != num-1)
                    return (ll)-7;
            }
            pow <<= 1;
        }

        return ans;
    };

    while(true)
    {
        ll ref = unpack(8);
        ll num_size = unpack(3);

        if(ref==-7 || num_size==-7)
            return;

        for(ll i = 0; i < b; ++i)
        {
            ll x = unpack(num_size);
            if(x==-7)
                return;
            cout << x+ref << '\n';
            ++cnt;
            if(cnt >= n)
                return;
        }
    }
}

signed main()
{
    fio;
    solve();
}
