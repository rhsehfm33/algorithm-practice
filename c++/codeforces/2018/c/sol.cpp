#include <bits/stdc++.h>

using namespace std;

int _ti;

int dfs(vector<vector<int>>& u2v, vector<int>& alive, int pu, int u, int l) {
    ++alive[l];

    int mx = l;
    for (int v : u2v[u]) {
        if (v != pu) {
            mx = max(mx, dfs(u2v, alive, u, v, l + 1));
        }
    }
    --alive[mx + 1];

    return mx;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 2);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int ans = n - 1;
    vector<int> alive(n + 2);
    dfs(u2v, alive, 0, 1, 1);
    for (int i = 1, active = 0; i <= n; ++i) {
        active += alive[i];
        ans = min(ans, n - active);
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