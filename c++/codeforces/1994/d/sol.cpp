#include <bits/stdc++.h>

using namespace std;

int _ti;

struct DSU {
    vector<int> p;

    DSU(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
        }
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (x < y) {
            p[y] = x;
        } else {
            p[x] = y;
        }
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    DSU dsu(n + 1);
    vector<array<int, 2>> ans(n, {-1, -1});
    vector<vector<int>> r(n, vector<int>(n, -1));
    for (int i = 1; i <= n; ++i) {
        for (int j = n - 1; j > 0; --j) {
            if (ans[j][0] != -1) {
                continue;
            }

            int& u = r[j][a[i] % j];
            if (u == -1) {
                u = i;
            } else if (dsu.merge(u, i)) {
                ans[j] = {u, i};
                ++cnt;
            }
        }
    }

    if (cnt != n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n - 1; ++i) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
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