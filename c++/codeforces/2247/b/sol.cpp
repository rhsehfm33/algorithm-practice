#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    if (k > m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        if (i % k) {
            cout << "1 ";
        } else {
            cout << m - k + 1 << ' ';
        }
    }
    cout << '\n';
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