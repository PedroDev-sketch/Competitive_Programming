#include <bits\stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    map<int, int> prefixSum;
    prefixSum[0] = 1;
    int count = 0;
    ll sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += x[i];
        if(prefixSum.find(sum - k) != prefixSum.end())
        {
            count += prefixSum[sum - k];
        }
        prefixSum[sum]++;
    }

    cout << count << endl;

    return 0;
}