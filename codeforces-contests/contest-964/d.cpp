#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, t;
        cin >> s >> t;
        queue<char> pan;

        for(int i = 0; i < t.length(); i++)
        {
            pan.push(t[i]);
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == pan.front() && !pan.empty())
            {
                pan.pop();
            }
            else if(s[i] == '?')
            {
                if(!pan.empty())
                {
                    s[i] = pan.front();
                    pan.pop();
                }
                else s[i] = 'a';
            }
        }

        if(pan.empty())
        {
            cout << "YES" << endl << s << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}