#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    vector<int> arm(n, 1e6), acm(m, 1e6), brm(n, 1e6), bcm(m, 1e6);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            arm[i] = min(arm[i], a[i][j]);
            acm[j] = min(acm[j], a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
            brm[i] = min(brm[i], b[i][j]);
            bcm[j] = min(bcm[j], b[i][j]);
        }
    }

    vector<array<int, 2>> am(n * m + 1), bm(n * m + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            am[a[i][j]] = {arm[i], acm[j]};
            bm[b[i][j]] = {brm[i], bcm[j]};
        }
    }

    for (int i = 1; i <= n * m; ++i) {
        if (am[i] != bm[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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