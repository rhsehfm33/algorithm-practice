#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> b(n + 1);
    vector<vector<array<ll, 2>>> u2v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0, s, t, w; i < m; ++i) {
        cin >> s >> t >> w;
        u2v[s].push_back({t, w});
    }

    ll l = 0, h = 2e9;
    while (l <= h) {
        vector<ll> dp(n + 1, -1);
        dp[1] = 0;

        ll m = (l + h) / 2;
        for (ll u = 1; u <= n; ++u) {
            if (dp[u] == -1) {
                continue;
            }
            for (auto [v, w] : u2v[u]) {
                if (w <= m and dp[u] + b[u] >= w) {
                    dp[v] = max(dp[v], dp[u] + b[u]);
                }
            }
        }
        if (dp[n] != -1) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << (l > 1e9 ? -1 : l) << '\n';
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