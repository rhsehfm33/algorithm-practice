#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + 1 != c) {
        cout << "-1\n";
        return;
    }

    int p = (int)log2(a + 1);
    cout << p + (c - 1 + b + (a - (1 << p) + 1) * 2) / c << '\n';
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