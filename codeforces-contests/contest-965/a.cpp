#include <bits\stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main()
{
    ll t;
    cin >> t;

    int lower_bound = 1;
    int upper_bound = 100;

    while(t--)
    {
        ll k, xc, yc;
        cin >> xc >> yc >> k;
        vector<pair<ll, ll>> cd(k);

        if(k == 1)
        {
            cout << xc << " " << yc << endl;
            continue;
        } 

        ll xcount = 0, ycount = 0;
        for(ll i = 0; i < k - 1; i++)
        {
            cd[i].first = lower_bound + rand() % (upper_bound - lower_bound + 1);
            xcount += cd[i].first;

            cd[i].second = lower_bound + rand() % (upper_bound - lower_bound + 1);
            ycount += cd[i].second;
        }

        cd[k-1].first = xc*k - xcount;
        cd[k-1].second = yc*k - ycount;

        for(ll i = 0; i < k; i++)
        {
            cout << cd[i].first << " " << cd[i].second << endl;
        }
    }

    return 0;
}