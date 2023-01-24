#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    unordered_map<int, vector<int>> u2v;
    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }

    int ans = 0;
    unordered_set<int> vis;
    vis.insert(1);
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int u = q.front(); q.pop();
        ans = max(ans, u);
        for (int v : u2v[u]) {
            if (vis.count(v) == 0) {
                vis.insert(v);
                q.push(v);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    solve();

    return 0;
}