#include <bits/stdc++.h>

using namespace std;

int go(vector<vector<int>>& u2v, vector<bool>& c, int u, int pu) {
    if (c[u]) {
        return u;
    }

    c[u] = true;
    for (int v : u2v[u]) {
        if (v == pu) {
            continue;
        }

        int r = go(u2v, c, v, u);
        if (r) {
            return r == u ? 0 : r;
        }
    }
    c[u] = false;
    return 0;
}

void solve(int _ti) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    if (a == b) {
        cout << "NO\n";
        return;
    }

    vector<bool> c(n + 1);
    go(u2v, c, 1, -1);

    vector<bool> vis(n + 1);
    vis[a] = vis[b] = true;
    queue<array<int, 2>> q;
    q.push({a, 1});
    q.push({b, 2});
    while (q.size()) {
        auto [u, t] = q.front(); q.pop();
        if (c[u] and t == 2) {
            cout << "YES\n";
            return;
        }

        for (int v : u2v[u]) {
            if (vis[v] == false) {
                vis[v] = true;
                q.push({v, t});
            }
        }
    }

    cout << "NO\n";
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