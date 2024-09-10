#include <bits/stdc++.h>

using namespace std;

int _ti;

void dfs(vector<vector<int>>& u2v, string& s, int u, int p,
int& c0, int& c1, int& cq, int& acq) {
    acq += s[u] == '?';
    if (u2v[u].size() == 1 and p != -1) {
        if (s[u] == '1') {
            ++c1;
        } else if (s[u] == '0') {
            ++c0;
        } else {
            ++cq;
        }
        return;
    }
    
    for (int v : u2v[u]) {
        if (v != p) {
            dfs(u2v, s, v, u, c0, c1, cq, acq);
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> u2v(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        u2v[--u].push_back(--v);
        u2v[v].push_back(u);
    }
    string s; cin >> s;

    int c0 = 0, c1 = 0, cq = 0, acq = 0, ans = 0;
    dfs(u2v, s, 0, -1, c0, c1, cq, acq);
    if (s[0] == '?') {
        ans = max(c0, c1) + (cq + (c0 == c1 ? acq % 2 : 0)) / 2;
    } else {
        ans = (s[0] == '0' ? c1 : c0) + (cq + 1) / 2;
    }
    cout << ans << '\n';
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