#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int l = 1, r = 999;
    while (l < r) {
        int result;
        int m1 = l + (r - l) / 3;
        int m2 = l + (r - l) * 2 / 3;
        cout << "? " << m1 << ' ' << m2 << endl;
        cin >> result;
        if (result == (m1 + 1) * (m2 + 1)) {
            r = m1;
        } else if (result == m1 * (m2 + 1)) {
            l = m1 + 1;
            r = m2;
        } else {
            l = m2 + 1;
        }
    }
    cout << "! " << l << endl;
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