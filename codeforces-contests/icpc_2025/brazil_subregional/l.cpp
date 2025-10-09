#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define rep(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define per(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define eb emplace_back

signed main()
{
    fio;
    ll n; cin >> n;
    map<string, pll> dict;
    vector<string> dict_words(n);
    for(ll i = 0; i < n; i++)
    {
        string s; ll x, y;
        cin >> s >> x >> y;
        dict_words[i]=s;
        dict[s] = make_pair(x, y);
    }

    ll m; cin >> m;
    vector<string> base(m);
    for(auto& b : base) cin >> b;

    ll q, k;
    cin >> q >> k;
    while(q--)
    {
        ll f; cin >> f;

        vector<string> query(f);
        for(auto& qs : query) cin >> qs;

        vector<string> candidates;
        for(ll i = k; i >= 1; i--)
        {
            ll l = 0;
            for(ll j = i; j < m; j++)
            {
                ll w=l;
                for(ll c = 0; w<j && query[f-i+c]==base[w]; w++, c++);
                if(w==j) candidates.eb(base[w]);
                l++;
            }

            if(!candidates.empty()) break;
        }

        for(auto qs : query) cout << qs << " ";

        if(candidates.empty())
        {
            cout << "*\n";
            continue;
        }

        ll best = 0; string ans = "saskatchwan";
        bool start = true;
        for(int i = 0; i < n; i++)
        {
            pll d = dict[dict_words[i]];
            string key = dict_words[i];
            
            ll num = 0;
            for(auto c : candidates)
            {
                pll ci{0,0};
                if(dict.find(c)!=dict.end())
                    ci = dict[c];
                num += ci.first * d.first + ci.second * d.second;
            }

            if(num > best || start)
            {
                best = num;
                ans = key;
                start=false;
            }
        }

        cout << ans << '\n';

        /* ll best=0;
        ll idx=0;
        for(ll i = 0; i < n; i++) 
        {
            ll score=0;
            for(ll j = 0; j < candidates.size(); j++) 
            {
                pll ci = {0, 0};
                if(dict.find(candidates[j])!=dict.end())
                    ci = dict[candidates[j]];

                // inner product
                score += dict[dict_words[i]].first * ci.first + dict[dict_words[i]].second * ci.second;
            }

            if(!i || score > best) {
                best = score;
                idx = i;
            }
        }
        candidates.clear();
        cout << dict_words[idx] << '\n'; */
    }

    return 0;
}