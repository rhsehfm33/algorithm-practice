#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int x, y, k;
    cin >> x >> y >> k;

    if (y < x) {
        cout << x << '\n';
    } else {
        cout << y + abs(x - y) - min(k, abs(x - y)) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}