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

vll pos(21);

void std_hanoi(ll disk, ll source, ll target, ll aux, queue<pll>& ans)
{
    if(disk<=0)
        return;
    else
    {
        std_hanoi(disk-1, source, aux, target, ans);
        ans.push(mp(source, target));
        std_hanoi(disk-1, aux, target, source, ans);
    }
}

void hanoi(ll disk, ll target, queue<pll>& ans)
{
    if(disk<=0)
        return;
    if(pos[disk]==target)
        hanoi(disk-1, target, ans);
    else
    {
        ll aux = 3 - pos[disk] - target;
        hanoi(disk-1, aux, ans);
        ans.push(mp(pos[disk], target));
        std_hanoi(disk-1, aux, target, pos[disk], ans);
    }
}

void solve()
{
    ll n; cin >> n;
    for(ll i = 0; i < 3; ++i)
    {
        ll t; cin >> t;
        for(ll j = 0; j < t; ++j)
        {
            ll disk; cin >> disk;
            pos[disk] = i;
        }
    }

    queue<pll> ans;
    hanoi(n, 1, ans);
    cout << ans.size() << '\n';
    while(!ans.empty())
    {
        char a = ans.front().ff + 'A', b = ans.front().ss + 'A';
        cout << a << ' ' << b << '\n';
        ans.pop();
    }
}

signed main()
{
    fio;
    solve();
}
