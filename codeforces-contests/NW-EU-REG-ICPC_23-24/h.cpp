#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define ff first
#define ss second
#define fio cin.tie(0)->ios::sync_with_stdio(0)

// #define meujeitoninjaoualgumacoisaassim

void solve(vll &xs, ll n, ll ones, ll twos)
{
    ll saveones = ones;
    sort(all(xs));
    
    if(n==1)
    {
        cout << xs[0] << '\n';
        return;
    }

    if (!ones)
    {
        string ans = to_string(xs[0]);
        for (ll i = 1; i < n; i++)
        {
            ans += '*' + (to_string(xs[i]));
        }

        cout << ans << '\n';
        return;
    }

    if (ones == 1 && n >= 2)
    {
        string ans = "(1+" + to_string(xs[1]) + ")";
        for (ll i = 2; i < n; i++)
        {
            ans += '*' + (to_string(xs[i]));
        }

        cout << ans << '\n';
        return;
    }

    string ans = "";
    for (ll i = ones+twos; i < n; i++)
    {
        ans += (to_string(xs[i]));
        if (i != n - 1 || ones)
            ans += '*';
    }

    string oneadd = "";
    string three = "(1+1+1)", two = "(1+1)", four = "(1+1+1+1)";
    string case1 = "(2+1)", case2 = "(2+1+1)";
    while(twos && ones)
    {
        if(ones==2 && twos == 1)
        {
            twos--; ones = 0;
            oneadd+=case2;
            break;
        }

        ones--; twos--;
        oneadd+=case1;
        if(ones - 1 > 0)
            oneadd += "*";
    }

    while (ones)
    {
        if (ones == 4)
        {
            oneadd += four;
            ones = 0;
            break;
        }

        if (ones == 2)
        {
            oneadd += two;
            ones = 0;
            break;
        }

        oneadd += three;
        if (ones - 3 > 0)
            oneadd += '*';
        ones -= 3;
    }

    if(twos)
    {
        if(ans.size()>0)
            ans += "*2";
        else ans += "2";

        twos--;
    }
    
    while(twos)
    {
        twos--;
        ans += "*2";
    }

    cout << ans;
    if(saveones)
    {
        cout << oneadd;
    }
    cout << '\n';
}

signed main()
{
    fio;
    ll n;
    cin >> n;
    ll ones = 0, twos = 0;
    vll xs(n);
    for (auto &x : xs)
    {
        cin >> x;
        ones += x == 1;
        twos += x == 2;
    }
    solve(xs, n, ones, twos);
}
