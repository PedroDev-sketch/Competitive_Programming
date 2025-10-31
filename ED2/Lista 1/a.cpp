#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fio cin.tie(0)->ios::sync_with_stdio(0)

signed main()
{

    fio;

    ll t; 
    
    cin >> t;

    while(t--) 
    {

        ll n; cin >> n;


        ll sum = 0;


        while(n)
        {

            sum += n;

            n>>=1;

        }

        cout << sum << '\n';

    }    



}



