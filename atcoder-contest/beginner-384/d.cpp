#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;

#define x first 
#define y second
#define int unsigned long

signed main()
{
    int n, S;
    cin >> n >> S;
    vector<int> A(n);

    for(auto& p : A)
    {
        cin >> p;
    }

    auto sum = reduce(A.begin(), A.end());
    S %= sum;

    for(int i = 0; i < n; i++)
    {
        A.emplace_back(A[i]);
    }

    set<int> prefixsum;
    prefixsum.emplace();
    int k = 0;
    for(auto p : A)
    {
        k+=p;
        prefixsum.insert(k);
    }

    for(auto p : prefixsum)
    {
        if(prefixsum.contains(p+S))
        {
            cout << "Yes" << '\n';
            return 0;
        }

    }
    cout << "No"<< '\n';

    return 0;
}