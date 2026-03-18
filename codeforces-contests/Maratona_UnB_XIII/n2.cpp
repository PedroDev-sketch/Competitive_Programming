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

void solve(const ll D, const ll y)
{
    ll x = 0, i = 0, d = D, step = 1;
    ll l = 0, r = 0;

    while(abs(step) < d)
    {
        d -= abs(step);

        x += step;
        l = min(l, x); r = max(r, x);

        //cout << "x-> " << x << '\n';
        
        if(i%2==0)
            step *= (-1);
        else
            step *= 2;

        i++;
    }

    //cout << "x-> " << x << '\n';
    if(step)
    {
        if(step < 0) d *= (-1); 
        x += d;
    } 

    if(x >= l && r >= x)
    {
        cout << "Nao\n";
        return;
    }

    /* cout << "x-> " << x << '\n';
    cout << "d-> " << d << '\n';
    cout << "step-> " << step << '\n'; */
    cout << "Sim\n" << y - x << '\n';
}

signed main()
{
    fio;
    ll d, y; cin >> d >> y;
    solve(d, y);
}



