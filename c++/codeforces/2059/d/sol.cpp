#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int _ti;

vector<vector<int>> set_u2v(int n) {
    vector<vector<int>> u2v(n + 1);
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    return u2v;
}

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    auto a2b = set_u2v(n);
    auto c2d = set_u2v(n);

    int ans = INF;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    dis[s1][s2]= 0;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, s1, s2});
    while (pq.size()) {
        auto [cd, a, c] = pq.top(); pq.pop();
        if (cd < dis[a][c]) {
            continue;
        }
        for (auto b : a2b[a]) {
            for (auto d : c2d[c]) {
                int nd = cd + abs(b - d);
                if (nd < dis[b][d]) {
                    dis[b][d] = nd;
                    pq.push({nd, b, d});
                }
                if (a == c and b == d) {
                    ans = min(ans, cd);
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
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