#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define ff first 
#define ss second 
#define fio cin.tie(0)->ios::sync_with_stdio(0)

//#define meujeitoninjaoualgumacoisaassim

void solve(vll& xs, ll n, ll s)
{
    if(n==1 || s==1)
    {
        cout << "1\n";
        return;
    }

    ll ans = 0, sockets = s-2;
    sort(all(xs));
    xs[n-1] = xs[n-2] = -1;

    queue<ll> rem1, rem2;

    ll l = 1, r = n-1;
    //ll k = r;

    //ll debug = 0;
    while(l < r)
    {
        ll buff_ans = 0, bsock = sockets;

        ll k = (l+r)/2;

        for(ll i = 0; i < k; i++)
        {
            ll x = xs[i];
            if(x%3==2)
                rem2.emplace(x);
            else if(x%3)
                rem1.emplace(x);
            else
            {
                buff_ans++;
                bsock -= x/3;
            }
        }

        while(!rem1.empty() && !rem2.empty())
        {
            ll n1 = rem1.front(), n2 = rem2.front();
            rem1.pop(); rem2.pop();

            ll num = n1 + n2;

            while(num%3) num++;

            buff_ans += 2;
            bsock -= num/3;
        }

        while(!rem1.empty())
        {
            ll n1 = rem1.front();
            rem1.pop();

            ll n2 = 0;
            if(!rem1.empty())
            {
                n2 = rem1.front();
                rem1.pop();
            }

            ll num = n1 + n2;

            while(num%3) num++;
            bsock -= num/3;

            if(n2)     
                buff_ans += 2;
            else
                buff_ans++;
            
        }

        while(!rem2.empty())
        {
            ll n1 = rem2.front();
            rem2.pop();

            while(n1%3) n1++;

            bsock -= n1/3;
            buff_ans++;
        }

        if(bsock >= 0 && buff_ans <= sockets)
        {
            ans = max(ans, buff_ans);
            //k += k/2;
            l = k;
        }
        else
        {
            //k /= 2;
            r = k;
        }

        if(abs(r-l) <= 1) break;

        /* debug++;
        if(debug > 100) break;

        cout << "ans-> " << ans << '\n';
        cout << "l and r -> " << l << ' ' << r << '\n';
        cout << "k-> " << k << '\n'; */
    }

    cout << ans + 2 << '\n';
}

signed main()
{
    fio;
    ll n, s; cin >> n >> s;
    vll xs(n); for(auto& x : xs) cin >> x;
    solve(xs, n, s);
}



