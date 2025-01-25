#include <bits/stdc++.h>
using namespace std;

int rearrange(map<char,int> histogram)
{
    int odd = 0;
    for(auto x : histogram)
    {
        if(x.second % 2) odd++;
    }

    return odd;
}

signed main()
{
    string s;
    cin >> s;
    map<char,int> hist;

    for(auto x : s)
    {
        hist[x]++;
    }

    //debug
    /* cout << "\n\n";
    for(auto x : hist)
    {
        cout << x.first << ": " << x.second << '\n';
    }
    cout << "\n\n"; */
    //debug

    int counter = rearrange(hist);
    /*
    for(int i = 0; i < s.length(); i++)
    {
        if(isReanrrangeable(hist)) break;

        if(s[i] != s[s.length() - 1 - i]) 
        {
            s[s.length() - 1 - i] = s[i]; 
            counter++;

            hist[s[i]]++;
            hist[s.length() - 1 - i]--;
            if(hist[s.length() - 1 - i] == 0) hist.erase(s.length() - 1 - i);
        }
    } */

    if(counter == 0 || counter == 1) cout << "First\n";
    else if(counter % 2) cout << "First\n";
    else cout << "Second\n";

    //debug
    //cout << counter << '\n';
    

    return 0;
}