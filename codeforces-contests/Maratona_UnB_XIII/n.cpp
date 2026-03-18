#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define ff first
#define ss second
#define fio cin.tie(0)->ios::sync_with_stdio(0)

vll xs, ys;

void solve(const ll d, const ll y)
{
    ll x = y;
    auto it = lower_bound(all(xs), d);
    ll idx = it - xs.begin();

    cout << '\n' << "-> " << x << '\n';
    cout << "xs[idx]-> " << xs[idx] << '\n';

    if((idx)%2==0)
        x -= (d - xs[idx]);
    else
        x += (d - xs[idx]);

        
    cout << "-> " << x << '\n';

    while(idx>=0)
    {
        if(idx%2==0)
            x -= ys[idx];
        else
            x += ys[idx];

        cout << "-> " << x << '\n';
        
        idx--;
    }

    ll pos = x, desl = 0;
    ll l = x, r = x;
    for(ll i = 0; i < ys.size() && desl + ys[i] < d; i++)
    {
        if(xs[i] > d) break;

        if(i%2==0)
            pos += ys[i];
        else 
            pos -= ys[i];
        
        desl += ys[i];
        
        l = min(l, pos);
        r = max(r, pos);

        if(y >= l && y <= r)
        {
            cout << "Nao\n";
            return;
        }
    }

    cout << "Sim\n" << x << '\n';
}

signed main()
{
    fio;
    
    ll psum = 1, num = 3; xs.eb(1); ys.eb(1);
    while(num <= 3e18)
    {
        psum += num;
        xs.eb(psum);
        ys.eb(num);
        num*=2;
    }

    ll d, y; cin >> d >> y;
    solve(d, y);
}



