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
        int n, k, flag = 0;
        cin >> n;
        vector<int> seats(n, 0);

        for(int i = 0; i < n; i++)
        {
            cin >> k;
            k--;

            seats[k] = 1;
            if(i == 0) continue;

            if(k == 0 && seats[k+1] == 0) flag = 1;
            else if(k == n-1 && seats[n-2] == 0) flag = 1;
            else if(seats[k-1] == 0 && seats[k+1] == 0) flag = 1;
        }

        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}