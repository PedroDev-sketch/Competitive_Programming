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

bool isPalindrome(string s, ll size)
{
    if(size%2 && s[size/2] == '1')
        return false;
    
    for(ll i = 0; i <= size/2; i++)
        if(s[i] != s[size - i - 1])
            return false;
    
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    bitset<31> bt(n);

    string str = bt.to_string();

    ll j = 0, k = 0;
    for (; j < str.size() && str[j] == '0'; j++);
    str = str.substr(j, str.size() - j);

    //cout << str << '\n';
    
    j = str.size()-1;
    for (; j >= 0 && str[j] == '0'; j--, k++);
    
    while(k--)
        str = '0' + str;
    
    //cout << str << '\n';
    
    bool ans = isPalindrome(str, (ll)str.size());
    cout << (ans ? "YES" : "NO") << '\n';
}

signed main()
{
    fio;
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}
