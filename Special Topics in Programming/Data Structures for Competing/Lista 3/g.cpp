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

void operate(char m, string& s)
{
    ll carry = 0;
    if(m == 'U')
    {
        string res = "";
        for(auto c : s)
        {
            ll curr = (c-'0') + carry*10;
            res += to_string(curr/2);
            carry = curr%2;
        }
        int idx = 0;
        for(auto r : res)
        {
            if(r != '0') break;
            idx++;
        }
        s = res.substr(idx);
    }
    else if(m == 'L')
    {
        for(ll i = (ll)s.size()-1; i >= 0; i--)
        {
            ll num = s[i]-'0';
            num*=2;
            num += carry;
            carry = 0;

            if(num > 9) carry = 1;
            num %= 10;
            s[i] = num+'0';
        }
        if(carry) s = '1' + s;
    }
    else
    {
        for(ll i = (ll)s.size()-1; i >= 0; i--)
        {
            ll num = s[i]-'0';
            num*=2;
            num += carry;
            carry = 0;

            if(num > 9) carry = 1;
            num %= 10;
            s[i] = num+'0';
        }

        if(carry) s = '1' + s;
        carry = 0;

        for(ll i = (ll)s.size()-1; i >= 0; i--)
        {
            ll num = s[i]-'0';
            num+=1;
            num += carry;
            carry = 0;

            if(num > 9) carry = 1;
            num %= 10;
            s[i] = num+'0';
            if(!carry) break;
        }

        if(carry) s = '1' + s;
    }
}

signed main()
{
    fio;

    ll n, x; string s;
    cin >> n >> x >> s;
    
    stack<char> xs;
    for(auto k : s)
    {
        if(k == 'U' && !xs.empty() && xs.top() != 'U') xs.pop();
        else xs.push(k);
    }

    s = "";
    while(!xs.empty())
    {
        s += xs.top();
        xs.pop();
    }

    reverse(all(s));
    //cout << s << " <-\n";

    for(auto k : s)
    {
        if(k == 'U') x /= 2;
        else if(k == 'L') x *= 2;
        else {x*=2;x++;}
    }

    cout << x << '\n';
    
    return 0;
}