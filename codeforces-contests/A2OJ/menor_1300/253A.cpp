#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{
    fio;
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
   
    ll b, g;
    cin >> b >> g;

    bool flag = false;
    if(b>=g) {cout<<"B"; b--;}
    else {cout<<"G"; flag = true; g--;}
    while(b && g)
    {
        if(flag){ cout << "B"; b--; flag=false;}
        else {cout << "G"; g--; flag=true;}
    }
    while(b--)cout<<"B";
    while(g--)cout<<"G";
    cout << '\n';
    
    return 0;
}