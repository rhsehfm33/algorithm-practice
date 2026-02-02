#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n + 2, vector<int>(1 << n));
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + (1 << i) < (1 << n); j += (1 << (i + 1))) {
            a[i + 1][j] = a[i][j] ^ a[i][j + (1 << i)];
        }
    }
    while (q--) {
        int b, c, ans = 0;
        cin >> b >> c;
        --b;

        for (int i = 0, bi = b; i < n; ++i) {
            int bi2 = (b & (1 << i)) ? bi - (1 << i) : bi + (1 << i);
            if (c < a[i][bi2] or (c == a[i][bi2] and bi2 < bi)) {
                ans += (1 << i);
            }
            c ^= a[i][bi2];
            bi = min(bi, bi2);
        }
        cout << ans << '\n';
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