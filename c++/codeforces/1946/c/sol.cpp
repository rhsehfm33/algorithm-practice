#include <bits/stdc++.h>

using namespace std;

int _ti;

array<int, 2> get_k(vector<vector<int>>& u2v, int u, int p, int mx) {
    int cc = 0, uc = 1;
    for (auto v : u2v[u]) {
        if (v != p) {
            auto [cc2, uc2] = get_k(u2v, v, u, mx);
            cc += cc2 + (uc2 >= mx);
            uc += (uc2 >= mx ? 0 : uc2);
        }
    }
    return {cc, uc};
}

void solve() {
    int s, n, k;
    cin >> n >> k;
    vector<vector<int>> u2v(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        u2v[u].push_back(v);
        u2v[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (u2v[i].size() == 1) {
            s = i;
        }
    }

    int l = 1, h = n;
    while (l <= h) {
        int m = (l + h) / 2;
        auto [cc, uc] = get_k(u2v, s, -1, m);
        if (cc - (uc < m) >= k) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    cout << l - 1 << '\n';
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