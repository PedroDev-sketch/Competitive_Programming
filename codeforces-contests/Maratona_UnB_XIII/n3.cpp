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
    ll pos = 0, idx = 0, desl = 0;
    ll l = 0, r = 0;

    while(desl < d)
    {
        cout << pos << '\n';
        if(idx%2==0)
            pos += ys[idx];
        else 
            pos -= ys[idx];

        l = min(l, pos), r = max(r, pos);

        desl += ys[idx];
        idx++;
    }

    cout << pos << '\n';
    if(pos >= l && pos <= r)
    {
        cout << "Nao\n";
        return;
    }

    cout << "Sim\n";
    cout << y - pos << '\n';
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



