#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, cnt = 0; cin >> n >> m;
    vector<int> vis(n + 1, -1);
    vector<vector<int>> u2v(n + 1), oe(2);
    while (m--) {
        int u, v; cin >> u >> v;
        u2v[u].push_back(v); u2v[v].push_back(u);
    }

    string ans = "Bob";
    queue<int> q;
    q.push(1);
    vis[1] = 0;
    while (q.size()) {
        int ql = q.size();
        while (ql--) {
            int u = q.front(); q.pop();
            oe[cnt % 2].push_back(u);
            for (int v : u2v[u]) {
                if (vis[u] == vis[v]) {
                    ans = "Alice";
                    break;
                }
                if (vis[v] == -1) {
                    vis[v] = (cnt + 1) % 2;
                    q.push(v);
                }
            }
        }
        ++cnt;
    }

    cout << ans << endl;
    while (n--) {
        if (ans == "Alice") {
            cout << "3 2" << endl;
            int i, c; cin >> i >> c;
        } else {
            int a, b; cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            if ((oe[1].empty() or a == 1) and oe[0].size()) {
                cout << oe[0].back() << ' ' << a << endl; oe[0].pop_back();
            } else {
                cout << oe[1].back() << ' ' << b << endl; oe[1].pop_back();
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