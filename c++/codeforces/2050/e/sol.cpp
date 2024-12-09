#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i < c.size(); ++i) {
        int ai = min((int)a.size(), i);
        int bi = i - ai;
        while (ai >= 0 and bi <= b.size()) {
            if (ai < a.size()) {
                dp[ai + 1][bi] = min(dp[ai + 1][bi], dp[ai][bi] + (a[ai] != c[i]));
            }
            if (bi < b.size()) {
                dp[ai][bi + 1] = min(dp[ai][bi + 1], dp[ai][bi] + (b[bi] != c[i]));
            }
            --ai;
            ++bi;
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
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