#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Logic:
 * T is "ababab..." -> T[i] = 'a' if i is even, 'b' if i is odd.
 * At step k, we have taken L elements from left and R from right. L + R = k.
 * Options:
 * 1. Pick Left: Index is L. New L becomes L + 1.
 * 2. Pick Right: Index is (n-1) - R = n - 1 - k + L. L remains same.
 */

void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;

    // dp[p] stores if it's possible to have L with parity p (0 for even, 1 for odd)
    vector<bool> dp(2, false);
    dp[0] = true; // Initially, L = 0, which is even.

    for (int k = 0; k < n; ++k) {
        vector<bool> next_dp(2, false);
        bool possible = false;

        for (int p = 0; p < 2; ++p) {
            if (!dp[p]) continue;

            // Option 1: Pick from Left (Index L has parity p)
            char leftChar = (p == 0 ? 'a' : 'b');
            if (x[k] == '?' || x[k] == leftChar) {
                next_dp[(p + 1) % 2] = true;
                possible = true;
            }

            // Option 2: Pick from Right (Index n - 1 - k + L has parity (n - 1 - k + p) % 2)
            int rightIdxParity = (n - 1 - k + p) % 2;
            if (rightIdxParity < 0) rightIdxParity += 2; // Handle potential negative
            
            char rightChar = (rightIdxParity == 0 ? 'a' : 'b');
            if (x[k] == '?' || x[k] == rightChar) {
                next_dp[p] = true;
                possible = true;
            }
        }

        dp = next_dp;
        if (!possible) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}