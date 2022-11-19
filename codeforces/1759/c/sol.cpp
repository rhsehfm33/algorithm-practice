#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b) {
        cout << "0\n";
    }
    else if (abs(a - b) >= x) {
        cout << "1\n";
    }
    else if ((abs(l - a) >= x and abs(l - b) >= x) or
            (abs(r - a) >= x and abs(r - b) >= x)) {
        cout << "2\n";
    }
    else if ((abs(l - a) >= x and abs(r - b) >= x) or
            (abs(r - a) >= x and abs(l - b) >= x)) {
        cout << "3\n";
    }
    else {
        cout << "-1\n";
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