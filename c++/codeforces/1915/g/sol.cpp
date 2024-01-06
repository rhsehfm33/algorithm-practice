#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    vector<vector<array<ll, 2>>> u2vw(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u2vw[u].push_back({v, w});
        u2vw[v].push_back({u, w});
    }
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    ll ans = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(1001, 1e18));
    dp[1][1000] = 0;
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 1000, 1});
    while (pq.size()) {
        auto [cc, cs, cu] = pq.top(); pq.pop();
        if (dp[cu][cs] != cc) {
            continue;
        }
        if (cu == n) {
            ans = min(ans, cc);
        }
        for (auto& [v, w] : u2vw[cu]) {
            ll ns = min(cs, s[cu]);
            ll nc = cc + w * ns;
            if (nc < dp[v][ns]) {
                dp[v][ns] = nc;
                pq.push({nc, ns, v});
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}