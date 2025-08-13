#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

const ll MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    if (m != n - 1) {
        cout << "0\n";
        return;
    }

    ll leaf = 0;
    vector<ll> cnt(n + 1);
    for (ll u = 1; u <= n; ++u) {
        if (u2v[u].size() == 1) {
            int v = u2v[u][0];
            ++cnt[v];
            if (u2v[v].size() - cnt[v] == 1) {
                ++leaf;
            }
        }
    }
    if (leaf > 2) {
        cout << "0\n";
        return;
    }

    ll ans = leaf == 2 ? 4 : 2;
    for (ll u = 1; u <= n; ++u) {
        if (u2v[u].size() == 1) {
            continue;
        }
        for (ll i = cnt[u]; i > 1; --i) {
            ans = (ans * i) % MOD;
        }
    }

    cout << ans << '\n';
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