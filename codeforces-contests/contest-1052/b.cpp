#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vvll = vector<vll>;
using vpll = vector<pll>;

#define all(xs) xs.begin(), xs.end()
#define rep(i, a, b) {for(ll i = (a); i <= (b); i++)}
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back

bool func(const vll& xs, const vll& ys)
{
    return xs.size()<ys.size();
}

signed main()
{
    fio;

    ll t; cin >> t;
    while(t--)
    {
        ll n, m; cin >> n >> m;
        vvll xs(n);
        vll nums(m, 0);

        ll check = 0;

        for(auto& x : xs)
        {
            ll num;
            cin >> num;
            vll ys(num);

            for(auto& y : ys)
            {
                cin >> y;
                if(!nums[y-1]) check++;
                nums[y-1]++;
            }

            x = ys;
        }

        bool flag = (check==m);

        if(flag)
        {
            ll counter = 0;
            for(ll i = 0; i < n && counter < 2; i++)
            {
                for(auto x : xs[i]) 
                {
                    if(nums[x-1] == 1)
                        flag = false;
                }

                if(!flag) flag = true;
                else counter++;
            }
            if(counter >= 2) {cout << "YES\n"; continue;}
        }

        cout << "NO\n";
    }

    return 0;
}