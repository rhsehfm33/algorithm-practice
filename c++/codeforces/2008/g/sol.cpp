#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int ngcd = 0;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        ngcd = gcd(ngcd, ai);
    }

    if (n == 1) {
        cout << k - 1 + (ngcd <= k - 1) << '\n';
        return;
    }

    int l = 0, h = n + k - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        int cnt = 1 + min(n - 1, (m - 1) / ngcd) + k;
        if (cnt - 1 >= m) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    cout << l - 1 << '\n';
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