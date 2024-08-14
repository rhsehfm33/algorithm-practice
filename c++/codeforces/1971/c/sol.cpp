#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;

    int i1 = a;
    while (i1 != c and i1 != d) {
        i1 = (i1 + 1) % 12;
    }

    int i2 = b;
    while (i2 != c and i2 != d) {
        i2 = (i2 + 11) % 12;
    }

    if (i1 == i2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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