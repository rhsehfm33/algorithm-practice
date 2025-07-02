#include <bits/stdc++.h>
using namespace std;
int _ti;

bool check(int l1, int b1, int l2, int b2, int l3, int b3) {
    if (l1 == b1 + b2 and l1 == b1 + b3 and l2 + l3 == l1) {
        return true;
    }
    if (l1 == l2 and l1 == l3 and b1 + b2 + b3 == l1) {
        return true;
    }
    return false;
}

void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (check(l1, b1, l2, b2, l3, b3)
    or  check(b1, l1, b2, l2, b3, l3)) {
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