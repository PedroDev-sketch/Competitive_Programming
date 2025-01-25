#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s, ans;
    vector<char> arr;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(!i)
        {
            if(s[i] == '.')
            {
                arr.push_back('0');
                i++;
            } 
            else if(s[i] == '-' && s[i+1] == '.')
            {
                arr.push_back('1');
                i += 2;
            
            }
            else
            {
                arr.push_back('2');
                i+= 2;
            }
        }
        
        if(s[i] == '.')
        {
            arr.push_back('0');
        } 
        else if(s[i] == '-' && s[i+1] == '.')
        {
            arr.push_back('1');
            i++;
        }
        else if(s[i] == '-' && s[i+1] == '-')
        {
            arr.push_back('2');
            i++;
        }

    }

    for(int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
    }

    cout << ans << '\n';

    return 0;
}