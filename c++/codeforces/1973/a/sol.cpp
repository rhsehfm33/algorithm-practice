#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int p1, p2, p3, ans = -1;
    cin >> p1 >> p2 >> p3;
    for (int i = 0; i <= min(p1, p2); ++i) {
        for (int j = 0; j <= min(p2, p3); ++j) {
            for (int k = 0; k <= min(p1, p3); ++k) {
                int r1 = p1 - i - k;
                int r2 = p2 - i - j;
                int r3 = p3 - j - k;
                if (r1 < 0 or r2 < 0 or r3 < 0 or r1 % 2 or r2 % 2 or r3 % 2) {
                    continue;
                }
                ans = max(ans, i + j + k);
            }
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