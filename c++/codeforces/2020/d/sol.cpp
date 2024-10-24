#include <bits/stdc++.h>

using namespace std;

int _ti;

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(11));
    while (m--) {
        int a, d, k;
        cin >> a >> d >> k;
        ++dp[a][d];
        --dp[a + d * k][d];
    }

    DSU dsu(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (dp[i][j]) {
                dsu.merge(i, i + j);
                if (i + j <= n) {
                    dp[i + j][j] += dp[i][j];
                }
            }
        }
    }

    set<int> ans;
    for (int i = 1; i <= n; ++i) {
        ans.insert(dsu.find(i));
    }
    cout << ans.size() << '\n';
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