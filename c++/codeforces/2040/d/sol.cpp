#include <bits/stdc++.h>

using namespace std;

int _ti;

int go(vector<vector<int>>& u2v, vector<int>& sum, int p, int u) {
    sum[u] = 1;
    for (int v : u2v[u]) {
        if (v != p) {
            sum[u] += go(u2v, sum, u, v);
        }
    }
    return sum[u];
}

void setTree(vector<vector<int>>& u2v, vector<int>& sum, vector<int>& ans, int p, int u, int inc) {
    int stack = 0;
    for (int v : u2v[u]) {
        if (v == p) {
            continue;
        }
        stack += sum[v];
        ans[v] = ans[u] + inc * (stack == 1 ? 1 : stack * 2);
        setTree(u2v, sum, ans, u, v, -inc);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int i = 1, u, v; i <= n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    vector<int> sum(n + 1);
    go(u2v, sum, 0, 1);

    vector<int> ans(n + 1);
    ans[1] = 1;
    setTree(u2v, sum, ans, 0, 1, 1);

    for (int i = 1; i <= n; ++i) {
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