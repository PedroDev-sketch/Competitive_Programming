#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second 
#define int ll

signed main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<string> blocks;

    if(n == 1)
    {
        cout << s << '\n';
        return 0;
    }

    string block;
    int kth = -1, kthmin = -1, check = 0;
    char last = s[0];
    for(int i = 0; i < n; i++)
    {
        if(s[i] != last)
        {
            blocks.push_back(block);
            block = "";
            if(last == '1'){ check++;
            if(check == k - 1) kthmin = blocks.size() - 1;
            else if(check == k) kth = blocks.size() - 1;}
        }

        if(s[i] == '1')
        {
            block.push_back('1');
        }
        else if(s[i] == '0')
        {
            block.push_back('0');
        }
        last = s[i];
    }
    if(block != blocks.back())
    { 
        blocks.push_back(block); 
        if(block[0] == '1')
        { 
            check++; 
            if(check == k) kth = blocks.size() - 1;
        }
    }

    int size = blocks.size();
    for(int i = 0; i < size; i++)
    {
        if(i == kth) i++;
        if(i >= size) break;
        cout << blocks[i];
        if(i == kthmin)
        {
            cout << blocks[kth];
        }
    }
    cout << '\n';

    return 0;
}