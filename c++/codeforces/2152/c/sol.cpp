#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, -1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] += b[i - 1] + a[i];
        if (i > 1) {
            c[i] = c[i - 1] + (a[i - 1] == a[i]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if (len % 3 or (b[r] - b[l - 1]) % 3) {
            cout << "-1\n";
        } else {
            cout << len / 3 + (c[r] - c[l - 1] ? 0 : 1) << '\n';
        }
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