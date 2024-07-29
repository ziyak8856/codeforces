#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// Function to compute the power of a number under modulo
long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to compute factorials and modular inverses of factorials
void computeFactorials(int n, vector<long long>& fact, vector<long long>& invFact) {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[n] = power(fact[n], MOD - 2, MOD); // Fermat's little theorem for modular inverse
    for (int i = n - 1; i >= 1; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
    invFact[0] = 1; // Inverse factorial of 0 is 1
}

// Main function to count valid permutations that meet the requirements
int countValidPermutations(int n, const vector<vector<int>>& requirements) {
    // Initialize DP table
    vector<vector<long long>> dp(n + 1, vector<long long>(n * (n - 1) / 2 + 1, 0));
    dp[0][0] = 1; // One way to have an empty array with 0 inversions

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k <= i * (i - 1) / 2; ++k) {
            for (int x = 0; x < i; ++x) {
                if (k >= x) {
                    dp[i][k] = (dp[i][k] + dp[i - 1][k - x]) % MOD;
                }
            }
        }
    }

    // Calculate the number of valid permutations
    long long result = 1;
    for (const auto& req : requirements) {
        int endi = req[0] + 1; // Convert 0-based index to length
        int cnti = req[1];
        result = result * dp[endi][cnti] % MOD;
    }

    return result;
}

int main() {
    int n = 3;
    vector<vector<int>> requirements = {{2, 2}, {1, 1}, {0, 0}};
    
    cout << countValidPermutations(n, requirements) << endl;
    return 0;
}
