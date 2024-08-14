#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> u2v(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u2v[--u].push_back(--v);
    }

    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (int v : u2v[i]) {
            dp[v] = min(dp[v], dp[i] + 1);
        }
        if (u2v[i].size()) {
            u2v[i] = {*max_element(u2v[i].begin(), u2v[i].end())};
        }
    }

    for (int l = 0, r = 0; r < n - 1; ++r) {
        while (l < r) {
            if (u2v[l].size() and dp[l] + 1 < u2v[l][0] - r) {
                break;
            }
            ++l;
        }
        if (l < r) {
            cout << 0;
        } else {
            cout << 1;
        }
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