#include <bits/stdc++.h>
using namespace std;

int _ti;

struct uf {
    vector<int> p, mn, mx;
    uf (int n) {
        for (int i = 0; i <= n; ++i) {
            p.push_back(i);
            mn.push_back(2e9);
            mx.push_back(-1);
        }
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y, int w) {
        x = find(x);
        y = find(y);
        if (x > y) {
            swap(x, y);
        }
        p[y] = x;
        mn[x] = min({mn[x], mn[y], w});
        mx[x] = max({mx[x], mx[y], w});
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> uvw(m);
    for (auto& [u, v, w] : uvw) {
        cin >> u >> v >> w;
    }
    sort(uvw.begin(), uvw.end(), [] (auto& l, auto& r) {
        return l[2] < r[2];
    });

    int ans = 2e9 + 6;
    uf vuf(n);
    for (auto& [u, v, w] : uvw) {
        vuf.merge(u, v, w);
        if (vuf.find(1) == vuf.find(n)) {
            ans = min(ans, vuf.mn[1] + vuf.mx[1]);
        }
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