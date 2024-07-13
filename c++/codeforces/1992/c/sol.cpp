#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = n; i >= k; --i) {
        cout << i << ' ';
    }
    for (int i = k - 1; i > m; --i) {
        cout << i << ' ';
    }
    for (int i = 1; i <= m; ++i) {
        cout << i << ' ';
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