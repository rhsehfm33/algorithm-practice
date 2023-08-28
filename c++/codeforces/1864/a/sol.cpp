#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int x, y, n;
    cin >> x >> y >> n;
    if (x > y - ((n - 1) * n / 2)) {
        cout << -1;
        return;
    }

    cout << x << ' ';
    for (int i = n - 2; i >= 1; --i) {
        cout << y - (i * (i + 1) / 2) << ' ';
    }
    cout << y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}