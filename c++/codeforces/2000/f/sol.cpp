#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> ab(n);
    for (auto& [a, b] : ab) {
        cin >> a >> b;
    }

    vector<vector<int>> best(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i) {
        auto [a, b] = ab[i];
        for (int j = 1, ac = 0, bc = 0; j <= min(k, a + b); ++j) {
            if (a - bc <= b - ac) {
                best[i][j] = best[i][j - 1] + a - bc;
                ++ac;
            } else {
                best[i][j] = best[i][j - 1] + b - ac;
                ++bc;
            }
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 2, MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        auto [a, b] = ab[i];
        for (int j = 0; j <= k; ++j) {
            for (int ki = 0; ki <= min(k - j, a + b); ++ki) {
                if (ki == a + b - 1) {
                    ki = min(ki + 1, k - j);
                }
                dp[i + 1][j + ki] = min(dp[i + 1][j + ki], dp[i][j] + best[i][ki]);
            }
        }
    }

    cout << (dp[n][k] == MAX ? -1 : dp[n][k]) << '\n';
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