#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int x, y, i = 1;
    cin >> x >> y;
    while (i <= max(x, y)) {
        if ((x & i) != (y & i)) {
            cout << i << '\n';
            return;
        }
        i <<= 1;
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