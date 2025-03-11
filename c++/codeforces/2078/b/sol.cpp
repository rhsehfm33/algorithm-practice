#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 1; i <= n; ++i) {
            cout << (i != n ? n : n - 1) << ' ';
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << (i != n - 1 ? n - 1 : n) << ' ';
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