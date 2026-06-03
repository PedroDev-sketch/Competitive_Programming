#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair

bool iskunlun(string s)
{
    for(ll i = 1; i < (ll)s.size(); i++)
        if(abs((s[i]-'0') - (s[i-1]-'0')) > 1)
            return false;

    return true;
}

signed main()
{   
    fio;

    ll k;
    cin >> k;

    ll num = 0;
    
    queue<ll> xs;
    for(int i = 1; i <= 9; i++)
        xs.push(i);

    while(k--)
    {
        num = xs.front();
        xs.pop();

        if(num % 10)
            xs.push(10*num + (num%10) - 1);

        xs.push(10*num + num%10);
        
        if(num%10 != 9)
            xs.push(10*num + (num%10) + 1);
    }

    cout << num << '\n';

    return 0;
}