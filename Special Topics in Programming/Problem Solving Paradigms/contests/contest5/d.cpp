#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back
#define int ll

void troca(vector<int>& xs, int l, int r)
{
    int save = xs[l];
    xs[l] = xs[r];
    xs[r] = save;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    deque<int> xs={n};

    for(int i = n-1; i >= 0; i--)
    {
        if(s[i] == 'L') xs.push_back(i);
        else xs.push_front(i);
    }

    for(int i = 0; i <= n; i++)
    {
        cout << xs[i] << ' ';
    }
    cout << '\n';

    return 0;
}