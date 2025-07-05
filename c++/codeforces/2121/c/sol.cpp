#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> rc(n), cc(m);
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0, mc = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > mx) {
                mx = a[i][j];
                mc = 1;
            } else if (a[i][j] == mx) {
                ++mc;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == mx) {
                ++rc[i];
                ++cc[j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (rc[i] + cc[j] - (a[i][j] == mx) == mc) {
                cout << mx - 1 << '\n';
                return;
            }
        }
    }
    cout << mx << '\n';
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