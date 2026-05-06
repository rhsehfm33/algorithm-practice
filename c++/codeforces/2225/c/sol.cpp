#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<string> vs(2);
    cin >> vs[0] >> vs[1];
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + (vs[0][i] != vs[1][i]));
        if (i + 1 < n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + (vs[0][i] != vs[0][i + 1]) + (vs[1][i] != vs[1][i + 1]));
        }
    }
    cout << dp[n] << '\n';
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