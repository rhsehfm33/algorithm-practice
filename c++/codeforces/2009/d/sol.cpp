#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n; cin >> n;
    vector<vector<int>> xy(2, vector<int>(n + 3));
    vector<vector<int>> xys(2, vector<int>(n + 3));
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        ++xy[y][++x];
    }

    for (int i = 1; i <= n + 1; ++i) {
        xys[0][i] += xy[0][i] + xys[0][i - 1];
        xys[1][i] += xy[1][i] + xys[1][i - 1];
    }
    
    long long ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
        if (xy[0][i] and xy[1][i]) {
            ans += xys[0][i - 1] + xys[1][i - 1];
            ans += (xys[0][n + 1] - xys[0][i]) + (xys[1][n + 1] - xys[1][i]);
        }
        ans += (xy[1][i] and xy[0][i - 1] and xy[0][i + 1]);
        ans += (xy[0][i] and xy[1][i - 1] and xy[1][i + 1]);
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