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
#define eb emplace_back

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

    ll n, q;
    cin >> n >> q;

    vll front(n+1, -1), back(n+1, -1);

    while(q--)
    {
        ll qt;
        cin >> qt;

        if(qt==3)
        {
            ll x;
            cin >> x;

            while(front[x] != -1)
            {
                x=front[x];
            }

            vll ans;
            while(x!=-1)
            {
                ans.eb(x);
                x=back[x];
            }
            cout << ans.size() << " ";
            for(auto a : ans) cout << a << " ";
            cout << '\n';
        }
        else
        {
            ll x, y; cin >> x >> y;

            if(qt==1)
            {
                front[y]=x;
                back[x]=y;
            }
            else
            {
                front[y]=-1;
                back[x]=-1;
            }
        }
    }

    return 0;
}