#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dp[0] = 1;
    dp[1] = a[1] == 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 2] + 1) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        if (a[i] == a[i - 1]) {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }
    }

    cout << (dp[n] + dp[n - 1]) % MOD << '\n';
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