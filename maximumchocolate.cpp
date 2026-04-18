#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long>> a(N, vector<long long>(N));
    vector<vector<long long>> dp(N, vector<long long>(N));

    // Input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    // Initialize first row
    for (int j = 0; j < N; j++) {
        dp[0][j] = a[0][j];
    }

    // Fill DP
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long up = dp[i-1][j];
            long long left = (j > 0) ? dp[i-1][j-1] : 0;
            long long right = (j < N-1) ? dp[i-1][j+1] : 0;

            dp[i][j] = a[i][j] + max({up, left, right});
        }
    }

    // Find max in last row
    long long ans = 0;
    for (int j = 0; j < N; j++) {
        ans = max(ans, dp[N-1][j]);
    }

    cout << ans;

    return 0;
}