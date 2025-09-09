#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    vector<int> dp(n + 1);
    vector<vector<int>> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        cnt[a[i]].push_back(i);
        int sz = cnt[a[i]].size();
        if (sz >= a[i]) {
            int pi = cnt[a[i]][sz - a[i]];
            dp[i + 1] = max(dp[i + 1], dp[pi] + a[i]);
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