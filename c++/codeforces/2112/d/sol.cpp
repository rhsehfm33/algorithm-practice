#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    int tu = -1;
    for (int i = 1; i <= n; ++i) {
        if (u2v[i].size() == 2) {
            tu = i;
            break;
        }
    }
    if (tu == -1) {
        cout << "NO\n";
        return;
    }

    vector<array<int, 2>> ans;
    auto dfs = [&](auto self, int u, int p, bool sw) -> void {
        if (sw) {
            ans.push_back({u, p});
        } else {
            ans.push_back({p, u});
        }
        for (int v : u2v[u]) {
            if (v != p) {
                self(self, v, u, !sw);
            }
        }
    };
    dfs(dfs, u2v[tu][0], tu, 0);
    dfs(dfs, u2v[tu][1], tu, 1);

    cout << "YES\n";
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
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