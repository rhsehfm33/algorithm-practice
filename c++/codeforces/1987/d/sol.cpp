#include <bits/stdc++.h>

using namespace std;


int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1), a2;
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++cnt[ai];
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            a2.push_back(cnt[i]);
        }
    }

    int n2 = a2.size();
    vector<vector<int>> dp(n2 + 1, vector<int>(n2 + 1));
    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j >= a2[i]) {
                dp[i + 1][j - a2[i]] = max(dp[i + 1][j - a2[i]], dp[i][j] + 1);
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
        }
    }

    cout << n2 - *max_element(dp[n2].begin(), dp[n2].end()) << '\n';
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