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
#define MAXN (1e9 + 7)
#define ff first
#define ss second

void solve()
{
    ll n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    map<char, multiset<ll>> ss, ts;
    for(ll i = 0; i < n; i++)
    {
        ts[t[i]].emplace(i);
        ss[s[i]].emplace(i);
    }

    ll op = 0;
    vector<string> ans;
    while(op < k)
    {
        op++;

        if(s==t)
        {
            cout << ans.size() << '\n';
            if(!ans.empty()) for(auto a : ans)
                cout << a << '\n';
            return;
        }

        string sl = s;
        char save = '1';
        ll idx_curr = 0;
        for(ll i = 1; i < n; i++)
        {
            if(save != '1')
            {
                if(sl[i]!=t[i] && ts[save].empty())
                    sl[i] = save;
                
                else
                {
                    ll idx_obj = *ts[save].rbegin();

                    if(idx_curr < idx_obj)
                        sl[i] = save;
                }
            }

            if(s[i]!=t[i])
            {
                ll idx_curr = *ss[sl[i]].rbegin();
                ss[sl[i]].erase(i);
                save = sl[i];
                sl[i]=s[i-1];
                ss[sl[i]].insert(i);
            }
        }

        s = sl;
        cout << "s-> " << s << '\n';
        ans.eb(s);
        if(s==t)
        {
            cout << ans.size() << '\n';
            if(!ans.empty()) for(auto a : ans)
                cout << a << '\n';
            return;
        }
    }

    cout << "-1\n";
    return;
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}



