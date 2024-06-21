#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, sx = 1e9, bx = 0, sy = 1e9, by = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                sx = min(sx, i);
                bx = max(bx, i);
                sy = min(sy, j);
                by = max(by, j);
            }
        }
    }

    cout << (sx + bx) / 2 << ' ' << (sy + by) / 2 << '\n';
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