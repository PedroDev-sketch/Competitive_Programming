#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 

signed main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int count = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'O') count++;
        else{
            ans += floor(count/k);
            count = 0;
        }
    }

    if(count != 0) ans += floor(count/k);

    cout << ans << '\n';
    

    return 0;
}