#include <bits/stdc++.h>

using namespace std;

int _ti;

struct DSU {
    vector<int> p;
    DSU(int n) {
        for (int i = 0; i <= n; ++i) {
            p.push_back(i);
        }
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x > y) {
            swap(x, y);
        }
        p[y] = x;
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> fuv(n + 1), guv(n + 1);
    DSU fdsu(n), gdsu(n); 
    for (int i = 0, u, v; i < m1; ++i) {
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        fuv[u].push_back(v);
    }
    for (int i = 0, u, v; i < m2; ++i) {
        cin >> u >> v;
        gdsu.merge(u, v);
        if (u > v) {
            swap(u, v);
        }
        guv[u].push_back(v);
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u) {
        int gru = gdsu.find(u);
        for (int fv : fuv[u]) {
            int grv = gdsu.find(fv);
            if (grv != gru) {
                ++ans;
            } else {
                fdsu.merge(u, fv);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        int fru = fdsu.find(u);
        int gru = gdsu.find(u);
        if (fru != gru) {
            ++ans;
            fdsu.merge(u, gru);
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