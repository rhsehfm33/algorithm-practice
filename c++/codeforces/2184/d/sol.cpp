#include <bits/stdc++.h>
using namespace std;

int dp[33][33];
int _ti;

void preset() {
    dp[0][0] = 1;
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j + 1] += dp[i][j];
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    int ln = log2(n);
    int ans = 0;
    for (int i = 0; i < ln; ++i) {
        for (int j = 0; j <= i and i + j < k; ++j) {
            ans += dp[i][j];
        }
    }
    ans += (ln + 1 <= k);
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}