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
    vll xs(n); queue<ll> ys, zs;
    ll batch = 0, ans = 0, idx = 0;
    for(auto& x : xs)
    {
        cin >> x;
        ys.push(x);

        if(x==abs(x) && idx)
            batch+=x;
        else if(batch)
        {
            zs.push(batch);
            batch=0;
        }

        ++idx;
    }

    if(batch)
        zs.push(batch);

    ll first = ys.front(); ys.pop();
    //cout << "zs test-> " << zs.front() << '\n'; 
    while(!ys.empty())
    {
        if(ys.size()==1)
        {
            ans += (first >= -ys.front() ? first : -ys.front());
            ys.pop();
        }

        else if(ys.front() <= 0)
        {
            if(zs.empty() && first > 0)
            {
                ll sum = 0, zc = ys.front();
                while(!ys.empty())
                {
                    if(ys.front() > zc)
                        zc = -ys.front();
                    sum -= ys.front();
                    ys.pop();
                }

                if(first > zc)
                {
                    ans += first;
                    ans += (sum - zc);
                }
                else
                    ans += sum;

                break;
            }

            ans -= ys.front();
            ys.pop();
        }

        else
        {
            if(first>=0)
            {
                ans+=first;
                first=ys.front();
                ys.pop();
            }

            else
            {
                if(-first <= zs.front())
                {
                    ans += first;
                    first = ys.front();
                    ys.pop();
                    zs.front() -= first;
                    if(zs.front() <= 0)
                        zs.pop();
                }
                else
                {
                    ans -= ys.front();
                    zs.front() -= ys.front();
                    if(zs.front() <= 0)
                        zs.pop();
                    ys.pop();
                }
            }
        }

        //cout << "-> " << ans << '\n';
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
