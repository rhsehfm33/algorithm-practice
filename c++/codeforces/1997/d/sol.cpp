#include <bits/stdc++.h>

using namespace std;

int _ti;

int dfs(vector<vector<int>>& u2v, vector<int>& a, int u) {
    if (u2v[u].size() == 0) {
        return a[u];
    }

    int result = 2e9;
    for (int v : u2v[u]) {
        result = min(result, dfs(u2v, a, v));
    }
    if (u == 1) {
        result += a[u];
    } else if (result > a[u]) {
        result = (result + a[u]) / 2;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> u2v(n + 1);
    for (int i = 2, pi; i <= n; ++i) {
        cin >> pi;
        u2v[pi].push_back(i);
    }

    cout << dfs(u2v, a, 1) << '\n';
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