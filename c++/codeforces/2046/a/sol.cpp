#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0, mx = -1e9;
    for (int i = 0; i < n; ++i) {
        if (a[0][i] >= a[1][i]) {
            ans += a[0][i];
            mx = max(mx, a[1][i]);
        } else {
            ans += a[1][i];
            mx = max(mx, a[0][i]);
        }
    }
    cout << ans + mx << '\n';
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