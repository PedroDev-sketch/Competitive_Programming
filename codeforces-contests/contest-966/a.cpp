#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string num;
        cin >> num;
        if(num == "10") 
        {
            cout << "NO" << endl;
            continue;
        }

        if(num[0] == '1' && num[1] == '0')
        {
            if(((num[2] - '0') == 1 && num.length() > 3) || (num[2] - '0') > 1)
            {
                cout << "YES" << endl;
                continue;
            }
        }

        cout << "NO" << endl;
    }

    return 0;
}