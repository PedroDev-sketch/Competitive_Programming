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

bool isprime(ll num)
{
    ll buff = num;
    while(true)
    {
        --buff;
        if(buff <= 1) break;
        if(num%buff==0) return false;
    }
    return true;
}

void solve()
{
    vll nums(101, 0);

    ll it = 0;
    for(ll i = 2; i < 101 && it < 20; ++i)
    {
        if(!nums[i])
        {
            ++it;
            cout << i << endl;
            string ans; cin >> ans;

            if(ans=="yes") continue;
            for(ll j = i; j < 101; j += i)
                nums[j] = 1;
        }
    }

    for(ll i = 2; i < 101; ++i)
    {
        if(!nums[i] && !isprime(i))
        {
            cout << "composite" << endl;
            return;
        }
    }
    cout << "prime" << endl;
}

signed main()
{
    solve();
}
