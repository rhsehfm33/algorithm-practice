#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m, k, gc = 0;;
    cin >> n >> m >> k;
    vector<string> b(n);
    for (auto& bi : b) {
        cin >> bi;
        for (auto& bij : bi) {
            gc += (bij == 'g');
        }
    }
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] += (b[i][j] == 'g');
            if (i) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j) {
                dp[i][j] += dp[i][j - 1];
            }
            if (i and j) {
                dp[i][j] -= dp[i - 1][j - 1];
            }
        }
    }



    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i][j] != '.') {
                continue;
            }
            int bx = min(n - 1, i + (k - 1));
            int sx = max(0, i - (k - 1));
            int by = min(m - 1, j + (k - 1));
            int sy = max(0, j - (k - 1));
            int s = dp[bx][by];
            if (sx) {
                s -= dp[sx - 1][by];
            }
            if (sy) {
                s -= dp[bx][sy - 1];
            }
            if (sx and sy) {
                s += dp[sx - 1][sy - 1];
            }
            ans = max(gc - s, ans);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}