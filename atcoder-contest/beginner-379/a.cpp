#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    string s;
    cin >> s;

    string fi, se;
    fi.push_back(s[1]);
    fi.push_back(s[2]);
    fi.push_back(s[0]);

    se.push_back(s[2]);
    se.push_back(s[0]);
    se.push_back(s[1]);

    cout << stoi(fi) << " " << stoi(se) << '\n';

    return 0;
}