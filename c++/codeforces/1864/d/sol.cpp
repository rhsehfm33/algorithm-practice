#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<string> nn(n);
    for (int i = 0; i < n; ++i) {
        cin >> nn[i];
    }

    int ans = 0;
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0, sum = 0; j < n; ++j) {
            sum += dp[i][j][0];

            int isOne = (nn[i][j] - '0' + sum) % 2;
            ans += isOne;
            if (i + 1 < n) {
                dp[i + 1][max(0, j - 1)][0] += dp[i][j][0] + isOne;
                dp[i + 1][min(n - 1, j + 1)][1] += dp[i][j][1] + isOne;
            }

            sum -= dp[i][j][1];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}