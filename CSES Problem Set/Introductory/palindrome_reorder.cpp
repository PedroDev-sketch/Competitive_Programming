#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

constexpr ll MOD = 1e9+7;
void solve()
{
    string s; cin >> s;
    map<char,ll> hs;
    for(auto x : s)
        hs[x]++;
    deque<char> ans;

    bool hasodd = false;
    char oddchar = ' ';
    for(auto [key, val] : hs)
    {
        //cout << key << ":" << val << '\n';
        if(val&1 && hasodd)
        {
            cout << "NO SOLUTION\n";
            return;
        }
        else if(val&1)
        {
            hasodd = true;
            oddchar = key;
        }
    }

    if(hasodd)
    {
        //cout << oddchar << '\n';
        while(hs.count(oddchar))
        {
            ans.push_back(oddchar);
            hs[oddchar]--;
            if(hs[oddchar] <= 0)
                hs.erase(oddchar);
        }
    }

    for(auto& [key, val] : hs)
    {
        while(val>0 && !(val&1))
        {
            ans.push_back(key);
            ans.push_front(key);
            val -= 2;
        }
    }

    
    while(!ans.empty())
    {
        cout << ans.front();
        ans.pop_front();
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
}
