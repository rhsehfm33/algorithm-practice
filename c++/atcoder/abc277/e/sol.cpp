#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> u2va(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, a;
        cin >> u >> v >> a;
        u2va[u].push_back({v, a});
        u2va[v].push_back({u, a});
    }

    unordered_set<int> s;
    for (int i = 0; i < K; ++i) {
        int si;
        cin >> si;
        s.insert(si);
    }

    int ans = 0;
    vector<vector<bool>> vis(2, vector<bool>(N + 1));
    vis[0][1] = true;
    queue<pair<int, int>> q;
    q.push({0, 1});
    while (q.size()) {
        int ql = q.size();
        while (ql--) {
            auto [csw, u] = q.front(); q.pop();
            if (u == N) {
                cout << ans << '\n';
                return;
            }

            for (auto [v, a] : u2va[u]) {
                if (((a ^ csw) or s.count(u)) and vis[a ^ 1][v] == false) {
                    vis[a ^ 1][v] = true;
                    q.push({a ^ 1, v});
                }
            }
        }
        ++ans;
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}