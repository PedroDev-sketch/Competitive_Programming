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

ll get_moves(ll disk, ll target)
{
    if(disk<=0) return 0;

    if(pos[disk]==target)
        return get_moves(disk-1, target);
    else
    {
        ll aux = 3 - pos[disk] - target;
        return get_moves(disk-1, aux) + 1 + ((1LL << (disk-1)) - 1);
    }
}

void std_hanoi(ll disk, ll source, ll target, ll aux)
{
    if(disk==0) return;
    std_hanoi(disk-1, source, aux, target);
    char a = 'A'+source, b = 'A'+target;
    cout << a << ' ' << b << '\n';
    std_hanoi(disk-1, aux, target, source);
}

void hanoi(ll disk, ll target)
{
    if(disk<=0) return;
    if(pos[disk]==target)
        hanoi(disk-1, target);
    else
    {
        ll aux = 3 - pos[disk] - target;
        hanoi(disk-1, aux);
        char a = 'A'+pos[disk], b = 'A'+target;
        cout << a << ' ' << b << '\n';
        std_hanoi(disk-1, aux, target, pos[disk]);
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
            ll d; cin >> d;
            pos[d] = i;
        }
    }

    ll target = 1;
    ll moves = get_moves(n, target);
    cout << moves << '\n';
    hanoi(n, target);
}

signed main()
{
    fio;
    solve();
}
