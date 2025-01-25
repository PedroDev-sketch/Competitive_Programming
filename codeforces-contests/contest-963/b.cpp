#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

bool iseven(ll num)
{
    return (num % 2 == 0);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, highestodd = 0, op = 0;
        cin >> n;
        vll even, odd;

        for(int i = 0; i < n; i++)
        {
            ll num;
            cin >> num;

            if(iseven(num)) even.push_back(num);
            else
            {
                odd.push_back(num);
                highestodd = max(highestodd, num);
            }
        }

        if(even.size() == 0 || odd.size() == 0)
        {
            cout << op << endl;
            continue;
        }

        sort(even.begin(), even.end());

        for(int i = 0; i < even.size(); i++)
        {
            if(highestodd > even[i])
            {
                highestodd += even[i];
            } 
            else
            {
                highestodd += even[even.size() - 1];
                i--;
            }
            op++;
        }

        cout << op << endl;
    }

    return 0;
}