#include <bits/stdc++.h>

using namespace std;

int _ti;

int dfs(vector<vector<int>>& u2v, int& ans, int p, int u) {
    int con = u2v[u].size();
    int mx1 = 0, mx2 = 0;
    for (int v : u2v[u]) {
        if (v != p) {
            int cr = dfs(u2v, ans, u, v);
            if (cr >= mx1) {
                mx2 = mx1;
                mx1 = cr;
            } else if (cr > mx2) {
                mx2 = cr;
            }
        }
    }
    ans = max(ans, con);
    ans = max(ans, mx1 + con - 1);
    ans = max(ans, mx1 + mx2 + con - 2);

    return max(con - 1, mx1 + con - 2);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int ans = 0;
    dfs(u2v, ans, 0, 1);
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