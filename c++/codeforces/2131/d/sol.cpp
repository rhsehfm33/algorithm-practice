#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int sum = 0, mx = 0;
    for (int u = 1; u <= n; ++u) {
        int cur = u2v[u].size() == 1;
        for (int v : u2v[u]) {
            cur += (u2v[v].size() == 1);
        }
        mx = max(mx, cur);
        sum += (u2v[u].size() == 1);
    }

    cout << sum - mx << '\n';
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