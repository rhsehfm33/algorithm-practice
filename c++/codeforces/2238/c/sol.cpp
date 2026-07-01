#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int _ti;

int go(vector<vector<int>>& u2v, int u, int& ans) {
    int d1 = 0, d2 = 0;
    for (int v : u2v[u]) {
        int d = go(u2v, v, ans);
        if (d > d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }
    ans += 1 + d2;
    return d1 + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> u2v(n + 1);
    for (int v = 2, u; v <= n; ++v) {
        cin >> u;
        u2v[u].push_back(v);
    }

    int ans = 0;
    go(u2v, 1, ans);
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