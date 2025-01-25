#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int k = 0; k < t; k++)
    {
        int n, ans = 0;
        vector<int> count(4);
        cin >> n;
        char arr[4*n];

        for(int i = 0; i < 4*n; i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < 4*n; i++)
        {
            if (arr[i] == 'A'){
                count[0]++;
            } else if(arr[i] == 'B') {
                count[1]++;
            } else if(arr[i] == 'C') {
                count[2]++;
            } else if(arr[i] == 'D'){
                count[3]++;
            }
        }

        for(int i = 0; i < 4; i++)
        {
            if(count[i] < n) ans += count[i];
            else ans += n;
        }

        cout << ans << endl;
        count.empty();
    }

    return 0;
}