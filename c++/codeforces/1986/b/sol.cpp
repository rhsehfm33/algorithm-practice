#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int mx = max({a[i - 1][j], a[i + 1][j], a[i][j - 1], a[i][j + 1]});
            if (a[i][j] > mx) {
                a[i][j] = mx;
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
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