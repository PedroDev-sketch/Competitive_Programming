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

//Retorna o número de triângulos retângulos possíveis, sendo os três lados
//menores ou iguais que n
void euclid_formula(ll n)
{
    ll ans = 0;
    for(ll m = 2; m * m <= n; m++)
    {
        for(ll k = 1; k < m; k++)
        {
            if(gcd(m, k) == 1 && (m - k) % 2 == 1)
            {
                ll c = (ll)m*m + (ll)k*k;
                if(c <= n) ans+=n/c;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    fio;
    
    ll n; cin >> n;

    euclid_formula(n);

    return 0;
}