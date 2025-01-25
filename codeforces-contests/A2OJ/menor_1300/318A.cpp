#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k, midpoint;
    cin >> n >> k;
    
    if(n%2)midpoint = n/2 + 2;
    else midpoint = n/2 +1;

    if(k >= midpoint)
    {
        k -= midpoint;
        k++;
        k *= 2;
    }
    else
    {
        k *= 2;
        k--;
    }

    cout  << k << '\n';

    return 0;
}