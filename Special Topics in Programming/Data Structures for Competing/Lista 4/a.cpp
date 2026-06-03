#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{   
    fio;

    ll n, k;
    cin >> n >> k;

    ll num = 1;
    while(n--)
    {
        if(num < k) num*=2;
        else num+=k;
    }

    cout << num << '\n';

    return 0;
}