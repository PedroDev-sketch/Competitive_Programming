#include <bits/stdc++.h> // Standard header for all common C++ libraries
using namespace std;
using ll = long long;       // Alias for long long to simplify type declarations

// Full-score Method 1: O(N^3 * X)
ll method1_count(int N, int A, const vector<int>& Xs) {
    // Determine the maximum value among cards and target A for DP sizing
    int Xmax = max(*max_element(Xs.begin(), Xs.end()), A);
    int maxS = N * Xmax;      // Maximum possible sum when choosing all cards
    
    // 3D DP table: dp[j][k][s] = number of ways to choose k cards from first j cards with sum s
    vector<vector<vector<ll>>> dp(
        N+1, vector<vector<ll>>(N+1, vector<ll>(maxS+1, 0))
    );
    dp[0][0][0] = 1;           // Base case: zero cards chosen from zero gives sum 0 in exactly 1 way

    for (int j = 1; j <= N; ++j) {
        int xj = Xs[j-1];       // Current card value
        for (int k = 0; k <= j; ++k) {
            for (int s = 0; s <= maxS; ++s) {
                // Case 1: do not include the j-th card
                dp[j][k][s] = dp[j-1][k][s];
                
                // Case 2: include the j-th card, if we still need k>0 and sum allows
                if (k > 0 && s >= xj) {
                    dp[j][k][s] += dp[j-1][k-1][s - xj];
                }
            }
        }
    }
    
    ll ans = 0;                // Variable to accumulate the count of valid selections
    for (int k = 1; k <= N; ++k) {
        int target = k * A;     // Required sum to achieve average A with k cards
        if (target <= maxS) ans += dp[N][k][target];
    }
    return ans;                // Return total number of ways to reach average A
}

// Full-score Method 2: O(N^2 * X)
ll method2_count(int N, int A, const vector<int>& Xs) {
    // Compute max for DP bounds
    int Xmax = max(*max_element(Xs.begin(), Xs.end()), A);
    int NX = N * Xmax;        // Offset to shift negative sums into non-negative indices
    int M = 2 * NX;           // Total width of DP array

    // Compute y[i] = x[i] - A; selecting subset with sum y = 0 equates to average A
    vector<int> ys(N);
    for (int i = 0; i < N; ++i) ys[i] = Xs[i] - A;

    // 2D DP table: dp[j][t] = ways to choose subset from first j of y's summing to t - NX
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    dp[0][NX] = 1;             // Base case: empty subset gives sum 0 => index NX

    for (int j = 1; j <= N; ++j) {
        int yj = ys[j-1];       // Current shifted value
        for (int t = 0; t <= M; ++t) {
            // Case 1: do not include yj
            dp[j][t] = dp[j-1][t];
            
            // Case 2: include yj if resulting index is valid
            int prev = t - yj;
            if (0 <= prev && prev <= M) {
                dp[j][t] += dp[j-1][prev];
            }
        }
    }
    
    // Subtract the empty-subset count to exclude selecting zero cards
    return dp[N][NX] - 1;
}

int main() {
    ios::sync_with_stdio(false); // Speed up I/O by disabling sync with C I/O
    cin.tie(nullptr);            // Untie cin from cout to avoid unnecessary flushes

    int N, A;
    cin >> N >> A;              // Read number of cards and target average
    vector<int> Xs(N);
    for (int i = 0; i < N; ++i) cin >> Xs[i]; // Read card values

    // Compute result via Method 1; Method 2 gives the same answer
    ll ans1 = method1_count(N, A, Xs);
    // ll ans2 = method2_count(N, A, Xs);

    cout << ans1 << "\n";     // Output the final count
    return 0;                   // End of program
}
