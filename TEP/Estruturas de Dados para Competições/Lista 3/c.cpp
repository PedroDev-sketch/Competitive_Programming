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
    //fio;
    
    string s;
    cin >> s;

    stack<pair<char, ll>> xs;
    vll ys(s.size(), 0);
    for(ll i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') xs.push(make_pair(s[i], i));
        else
        {
            if(xs.empty()) ys[i] = -1;
            else xs.pop();
        }
    }

    while(!xs.empty())
    {
        auto [x, y] = xs.top();
        xs.pop();
        ys[y] = -1;
    }

    /* for(auto y : ys) cout << y << " ";
    cout << '\n'; */

    ll counter = 0, size = 0, seq_start = 0;
    bool seq = false;
    vll zs;
    for(ll i = 0; i < s.size(); i++)
    {
        if(ys[i] == 0 && !seq)
        {
            seq=true;
            seq_start = i;
        }

        if(ys[i] == -1 && seq)
        {
            seq=false;
            zs.eb(i-seq_start);
            size = max(size, i-seq_start);
        }
    }

    if(seq){size = max(size, ((ll)s.size() - seq_start)); zs.eb((ll)s.size() - seq_start);}
    for(auto z : zs) if(z == size) counter++;

    cout << size << " " << (counter ? counter : 1) << '\n';

    return 0;
}