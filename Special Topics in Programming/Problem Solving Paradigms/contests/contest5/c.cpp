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

bool isPalindrome(const string & s, int n)
{
    bool ans = true;
    for(int i = 0; i <= n/2; i++)
    {
        if(s[i] != s[n-1-i]) ans = false;
    }

    return ans;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();

    int bcount = 0, ecount = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a') bcount++;
        else break;
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(s[i] == 'a')
        {
            ecount++;
        }
        else break;
    }

    if(bcount > ecount) cout << "No\n";
    else
    {
        string add = "";
        int diff = ecount - bcount;
        while(diff--) add += 'a';

        s = add+s;

        if(isPalindrome(s, s.size())) cout << "Yes\n";
        else cout << "No\n";
    }


    return 0;
}