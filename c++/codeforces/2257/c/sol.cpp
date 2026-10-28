#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), ind(n + 1);
    for (int i = 2, pi; i <= n; ++i) {
        cin >> p[i];
        ++ind[p[i]];
    }
    int m;
    cin >> m;
    vector<bool> d(n + 1);
    for (int i = 0, ai; i < m; ++i) {
        cin >> ai;
        d[ai] = true;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (d[u]) {
            ans.push_back(u);
        }
        --ind[p[u]];
        if (!ind[p[u]]) {
            q.push(p[u]);
        }
    }

    ans.pop_back();
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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