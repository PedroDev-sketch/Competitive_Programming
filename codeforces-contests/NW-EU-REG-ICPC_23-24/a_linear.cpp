#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define ff first 
#define ss second 
#define fio cin.tie(0)->ios::sync_with_stdio(0)

//#define meujeitoninjaoualgumacoisaassim

void solve(vll& xs, ll n, ll s)
{
    if(n==1 || s==1)
    {
        cout << "1\n";
        return;
    }

    ll ans = 2, sockets = s-2;
    sort(all(xs));
    xs[n-1] = xs[n-2] = -1;

    queue<ll> rem1, rem2;
    vpll ys;
    for(ll i = 0; i < n-2; i++)
    {
        ll x = xs[i];
        if(x%3==2)
            rem2.emplace(x);
        else if(x%3)
            rem1.emplace(x);
        else
            ys.eb(x/3, 1);
    }

    while(!rem1.empty() && !rem2.empty())
    {
        ll n1 = rem1.front(), n2 = rem2.front();
        rem1.pop(); rem2.pop();

        ll num = n1 + n2;

        while(num%3) num++;
        ys.eb(num/3, 2);
    }

    while(!rem1.empty())
    {
        ll n1 = rem1.front();
        rem1.pop();

        ll n2 = 0;
        if(!rem1.empty())
        {
            n2 = rem1.front();
            rem1.pop();
        }

        ll num = n1 + n2;

        while(num%3) num++;
        if(n2) ys.eb(num/3, 2);
        else ys.eb(num/3, 1);
    }

    while(!rem2.empty())
    {
        ll n2 = rem2.front();
        rem2.pop();

        while(n2%3) n2++;
        ys.eb(n2/3, 1);
    }

    //cout << "sockets-> " << sockets << '\n';
    //sort(all(ys));
    for(auto y : ys)
    {
        //cout << y.ff << ' ';
        if(y.ff <= sockets && ans + y.ss <= s)
        {
            sockets -= y.ff;
            ans += y.ss;
        }
        //else break;
    }
    //cout << '\n';

    cout << ans << '\n';
}

signed main()
{
    fio;
    ll n, s; cin >> n >> s;
    vll xs(n); for(auto& x : xs) cin >> x;
    solve(xs, n, s);
}



