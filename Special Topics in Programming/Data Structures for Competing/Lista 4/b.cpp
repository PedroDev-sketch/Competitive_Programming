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

    string s;
    cin >> s;

    deque<ll> xs;
    for(ll i = (ll)s.size()-1; i >= 0; i--)
    {
        if(s[i]=='r')xs.push_front(i+1);
        else xs.push_back(i+1);
    }

    for(auto x : xs) cout << x << '\n';

    return 0;
}