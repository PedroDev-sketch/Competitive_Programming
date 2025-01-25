#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<char> alp(26);
    int count = 0, prev;
    cin >> s;
    
    for(int i = 0; i < 26; i++)
    {
        alp[i] = s[i];
    }

    auto k = find(alp.begin(), alp.end(), 'A');
    prev = distance(alp.begin(), k);
    for(int i = 1; i < 26; i++)
    {
        auto it = find(alp.begin(), alp.end(), 'A' + i);
        int dist = distance(alp.begin(), it);
        count += abs(dist - prev);
        prev = dist;
    }

    cout << count << endl;

    return 0;
}