#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> p[i];
    }
    vector<double> dp(n + 1);
    for (int i = n; i > 0; --i) {
        dp[i - 1] = max(dp[i], c[i] + dp[i] * ((100 - p[i]) / (double)100));
    }
    cout << fixed << dp[0] << '\n';
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