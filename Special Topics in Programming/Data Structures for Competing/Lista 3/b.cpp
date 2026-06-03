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
    
    ll n; string s;
    cin >> n >> s;
    
    stack<char> xs;
    ll op = 0, cls = 0;
    for(auto p : s)
    {
        if(p == ')')
        {
            if(cls) cls--;
            if(!xs.empty() && xs.top() == '(')
            {
                xs.pop();
            }
            else op++;
        }
        else 
        {
            xs.push('(');
            cls++;
        }
    }

    while(op--) cout << '(';
    cout << s;
    while(cls--) cout << ')';

    return 0;
}