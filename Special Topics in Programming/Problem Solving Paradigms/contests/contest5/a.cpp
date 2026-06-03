#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define int ll

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int up = pow(2, 31) - 1;
    int down = -pow(2, 31);

    string sup = to_string(up);
    string sdown = to_string(down);

    if(s.size() > 11) cout << "No\n";
    else
    {
        if(s[0] == '-')
        {
            if(s <= sdown) cout << "Yes\n";
            else cout << "No\n";
        }
        else
        {
            if(s <= sup) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    /* if((s.size() == 10 && (s[0] - '0') > 2) || (s.size() == 11 && (s[1] - '0') > 2)) cout << "No\n";
    else if(s[0] == '-' && s.size() <= 11) 
    {
        if(stoi(s) >= pow(2, 31) * (-1)) cout << "Yes\n";
    }
    else if(s.size() <= 10) 
    {
        if(stoi(s) <= pow(2, 31)-1) cout << "Yes\n";
    }
    else cout << "No\n"; */
    
    return 0;
}