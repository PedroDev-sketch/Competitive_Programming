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

void solve()
{
    ll n; cin >> n;
    vll xs(n); map<ll, ll> hs;
    for(auto& x : xs)
    {
        cin >> x;
        hs[x]++;
    } 

    for(ll i = 0; i < n; ++i)
    {
        ll num = xs[i], seq = 0;
        map<ll, ll> bhs = hs;
        queue<ll> ys;

        while(!bhs.empty() && bhs.count(num))
        {
            ys.push(num);
            ++seq;
            --bhs[num];
            if(bhs[num]==0) bhs.erase(num);

            if(num%3==0 && bhs.count(num/3))
                num /= 3;
            else if(bhs.count(num*2))
                num *= 2;
        }

        if(seq==n)
        {
            while(!ys.empty())
            {
                cout << ys.front() << " ";
                ys.pop();
            }
            cout << '\n';
            return;
        }
        //else cout << seq << '\n';
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
