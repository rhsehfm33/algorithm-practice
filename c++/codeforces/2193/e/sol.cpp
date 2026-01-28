#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n + 1, INF);
    for (auto& ai : a) {
        cin >> ai;
        dp[ai] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                dp[i] = min(dp[i], dp[i / j] + dp[j]);
            }
        }
        cout << (dp[i] == INF ? -1 : dp[i]) << ' ';
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