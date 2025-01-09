#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int l, r;
    cin >> l >> r;

    int a = 0, b = 0, c = 0, bi = 1 << 29;
    while ((l & bi) or !(r & bi)) {
        int d = (bi & l & r);
        a |= d;
        b |= d;
        c |= d;
        bi >>= 1;
    }

    a |= (bi - 1);
    b |= bi;
    c = b != r ? b + 1 : a - 1;

    cout << a << ' ' << b << ' ' << c << '\n';
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