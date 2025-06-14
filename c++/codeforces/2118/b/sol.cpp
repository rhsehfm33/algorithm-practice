#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    cout << 2 * n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << 1 << ' ' << i << '\n';
        cout << i << ' ' << min(i + 1, n) << ' ' << n << '\n';
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
