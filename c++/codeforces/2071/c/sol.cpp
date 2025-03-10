#include <bits/stdc++.h>

using namespace std;

int _ti;

void dfs(vector<vector<int>>& u2v, vector<array<int, 2>>& ans, int u, int p, int l) {
    ans.push_back({l, u});
    for (auto v : u2v[u]) {
        if (v != p) {
            dfs(u2v, ans, v, u, l + 1);
        }
    }
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    vector<array<int, 2>> ans;
    dfs(u2v, ans, en, 0, 1);
    sort(ans.begin(), ans.end(), greater<array<int, 2>>());
    for (int i = 0; i < n; ++i) {
        cout << ans[i][1] << ' ';
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