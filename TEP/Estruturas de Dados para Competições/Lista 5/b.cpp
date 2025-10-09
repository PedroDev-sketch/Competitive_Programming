#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

void solve()
{
    ll n; cin >> n;
    map<string, ll> hs;
    while(n--)
    {
        string s; cin >> s;
        hs[s]++;
    }

    cout << "AC x " << hs["AC"] << '\n';
    cout << "WA x " << hs["WA"] << '\n';
    cout << "TLE x " << hs["TLE"] << '\n';
    cout << "RE x " << hs["RE"] << '\n';
}

signed main()
{
    fio;
    //ll t; cin >> t;
    solve();
    return 0;
}