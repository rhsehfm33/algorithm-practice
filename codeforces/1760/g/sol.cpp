#include <bits/stdc++.h>

using namespace std;

set<int> getXors(vector<vector<pair<int, int>>>& u2v, int s, int b) {
    set<int> xors;
    queue<pair<int, int>> q;
    q.push({s, 0});
    vector<bool> vis(u2v.size());
    vis[s] = true;
    while (q.size()) {
        auto [u, x] = q.front(); q.pop();
        for (auto [v, w] : u2v[u]) {
            if (vis[v] == false and v != b) {
                vis[v] = true;
                q.push({v, x ^ w});
                xors.insert(x ^ w);
            }
        }
    }

    return xors;
}

void solve(int _ti) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<pair<int, int>>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u2v[u].push_back({v, w});
        u2v[v].push_back({u, w});
    }

    set<int> axors = getXors(u2v, a, b);
    axors.insert(0);
    set<int> bxors = getXors(u2v, b, b);
    for (int axor : axors) {
        if (bxors.count(axor)) {
            cout << "YES\n";
            return;
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