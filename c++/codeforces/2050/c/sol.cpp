#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    vector<bool> dp(9);
    dp[0] = true;

    string n;
    cin >> n;
    for (int i = 0; i < n.size(); ++i) {
        vector<bool> ndp(9);
        for (int j = 0; j < 9; ++j) {
            if (dp[j]) {
                int d = n[i] - '0';
                ndp[(j + d) % 9] = true;
                if (n[i] < '4') {
                    ndp[(j + d * d) % 9] = true;
                }
            }
        }
        dp = ndp;
    }

    cout << (dp[0] ? "YES" : "NO") << '\n';
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