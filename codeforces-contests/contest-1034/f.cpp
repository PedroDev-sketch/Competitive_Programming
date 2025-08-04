#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
#define all(xs) xs.begin(), xs.end()
#define int ll

const ll MAXN = 1e5+7;

vector<bool> primo(MAXN + 1, true);

void crivoEratostenes(int n = MAXN) 
{
    primo[0] = primo[1] = false; 
    for (int p = 2; p * p <= n; p++) 
    {
        if (primo[p]) 
        {
            for (int i = p * p; i <= n; i += p) 
            {
                primo[i] = false;
            }
        }
    }
}

vll findDivisors(int n)
{
    vll divisors;

    // Iterate only up to the square root of n
    for (int i = 1; i <= sqrt(n); i++)
    {
        // Check if i is a divisor of n
        if (n % i == 0 && primo[i])
        {
            // Add divisor i to the vector
            divisors.push_back(i);

            // Check if i and n/i are different to avoid duplicates
            if (i != n / i && primo[n/i])
            {
                    // Add the paired divisor n / i to the vector
                divisors.push_back(n / i);
            }
        }
    }

    // Return the vector containing all divisors
    return divisors;
}

signed main()
{
    //cin.tie(0)->ios::sync_with_stdio(0);
    ll t;
    cin >> t;

    crivoEratostenes();

    while(t--)
    {
        ll n;
        cin >> n;

        vll xs(n+1);
        vector<bool> ys(n+1, false);

        iota(all(xs), 0);

        for(auto x : xs) cout << x << " ";
        cout << '\n';

        queue<ll> fila;
        for(int i = 1; i <= n; i++)
        {
            if(primo[xs[i]] && i * 2 >= n) ys[i] = true;
            else if(primo[xs[i]]) 
            {
                fila.push(xs[2*i]);
                xs[2*i] = xs[i];
                ys[2*i] = true;
            }
            else fila.push(xs[i]);
        }

        while(!fila.empty())
        {
            ll novo = fila.front();
            fila.pop();

            vll div = findDivisors(novo);
            for(auto d : div)
            {
                if(ys[d-1]) continue;
                else
                {
                    ys[d-1] = true;
                    xs[d-1] = novo;
                }
            }
        }

        for(auto x : xs) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}