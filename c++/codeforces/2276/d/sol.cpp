#include <bits/stdc++.h>
using namespace std;

int _ti;

int go(vector<vector<int>>& u2v, vector<bool>& vis, int u) {
    if (u2v[u].size() == 0) {
        return -1;
    }
    vis[u] = true;
    int cnt = u2v[u].size() >= 2;
    for (int v : u2v[u]) {
        if (!vis[v]) {
            cnt += go(u2v, vis, v);
        }
    }
    return cnt;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> vis(n + 1);
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        int r = go(u2v, vis, i);
        if (r == -1) {
            cout << "Brain Melt\n";
            return;
        }
        c += max(1, r);
    }
    cout << (c == 1 ? "2" : "Many") << '\n';
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