#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> u2v(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        if (u2v[i].size() == 1) {
            continue;
        }

        for (int v : u2v[i]) {
            if (u2v[v].size() == 1) {
                y = u2v[i].size() - 1;
            }
            else {
                x = u2v[v].size();
            }
        }

        if (y != 0) {
            break;
        }
    }

    cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}