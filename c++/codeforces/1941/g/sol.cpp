#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, b, e;
    cin >> n >> m;
    map<int, vector<int>> c2us;
    vector<vector<int>> u2cs(n + 1);
    for (int i = 0, u, v, c; i < m; ++i) {
        cin >> u >> v >> c;
        u2cs[u].push_back(c);
        u2cs[v].push_back(c);
        c2us[c].push_back(u);
        c2us[c].push_back(v);
    }
    cin >> b >> e;
    if (b == e) {
        cout << "0\n";
        return;
    }

    set<int> vc, vv;
    queue<int> cq;
    for (auto& c : u2cs[b]) {
        cq.push(c);
        vc.insert(c);
    }
    vv.insert(b);

    for (int cnt = 1; cq.size(); ++cnt) {
        int ql = cq.size();
        while (ql--) {
            int c = cq.front(); cq.pop();
            for (auto u : c2us[c]) {
                if (u == e) {
                    cout << cnt << '\n';
                    return;
                }
                if (vv.count(u)) {
                    continue;
                }
                vv.insert(u);

                for (auto& c : u2cs[u]) {
                    if (!vc.count(c)) {
                        vc.insert(c);
                        cq.push(c);
                    }
                }
            }
        }
    }
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