#include <bits/stdc++.h>
using namespace std;
int _ti;

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a > b) {
        cout << ((a ^ 1) == b ? y : -1) << '\n';
        return;
    }

    int c0 = b / 2 - a / 2;
    int c1 = (b + 1) / 2 - (a + 1) / 2;
    cout << c0 * x + c1 * min(x, y) << '\n';
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