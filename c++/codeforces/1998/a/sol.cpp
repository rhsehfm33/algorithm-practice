#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int x, y, k, inc = 1;
    cin >> x >> y >> k;
    while (k >= 2) {
        cout << x + inc << ' ' << y + inc << '\n';
        cout << x - inc << ' ' << y - inc << '\n';
        k -= 2;
        ++inc;
    }
    if (k == 1) {
        cout << x << ' ' << y << '\n';
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