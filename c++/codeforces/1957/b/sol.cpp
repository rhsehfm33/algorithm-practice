#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << '\n';
        return;
    }

    int b = (1 << (int)log2(k)) - 1;
    cout << b << ' ' << k - b;
    for (int i = 3; i <= n; ++i) {
        cout << " 0";
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