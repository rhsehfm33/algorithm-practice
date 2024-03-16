#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    set<int> ans;

    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][--x] = true;
    for (int i = 0; i < m; ++i) {
        int r;
        char c;
        cin >> r >> c;
        for (int j = 0; j < n; ++j) {
            if (!dp[i][j]) {
                continue;
            }
            
            if (c == '0' or c == '?') {
                dp[i + 1][(j + r) % n] = true;
                if (i == m - 1) {
                    ans.insert((j + r) % n + 1);
                }
            }
            if (c == '1' or c == '?') {
                dp[i + 1][(j - r + n) % n] = true;
                if (i == m - 1) {
                    ans.insert((j - r + n) % n + 1);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& ansi : ans) {
        cout << ansi << ' ';
    }
    cout << '\n';
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