#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n + 1, vector<int>(4, 1e9));
    for (auto& ai : a) {
        cin >> ai;
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                int jk = j | k;
                int w = jk == 1 ? 2 : (jk == 3 ? 4 : 0);
                if (w >= a[i]) {
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + __builtin_popcount(k));
                } else {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
                }
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
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