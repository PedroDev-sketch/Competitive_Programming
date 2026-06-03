#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

#define all(xs) xs.begin(), xs.end()

signed main()
{
    ll n;
    n = 6;

    vll xs(n);
    for(auto& x : xs) cin >> x;

    vll ys(n);
    for(auto& y : ys) cin >> y;

    sort(all(ys));
    ll counter = 0;
    for(auto x : xs)
        if(binary_search(all(ys), x)) counter++;

    if(counter < 3) cout << "azar";
    else if(counter < 4) cout << "terno";
    else if(counter < 5) cout << "quadra";
    else if(counter < 6) cout << "quina";
    else cout << "sena";


    

    return 0;
}