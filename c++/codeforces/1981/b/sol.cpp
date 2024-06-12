#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = n;
    int b = n + m;
    int s = max(0, n - m);
    for (int i = (1 << 30); i > 0; i >>= 1) {
        if ((b & i) and !(s & i)) {
            ans = (b | i | (i - 1));
            break;
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