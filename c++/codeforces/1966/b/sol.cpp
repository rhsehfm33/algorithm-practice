#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    array<int, 2> wb = {0, 0};
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1, c; y <= m; ++y) {
            char ch;
            cin >> ch;
            c = ch == 'W';
            if (x == 1) {
                wb[c] |= 1;
            }
            if (x == n) {
                wb[c] |= 2;
            }
            if (y == 1) {
                wb[c] |= 4;
            }
            if (y == m) {
                wb[c] |= 8;
            }
        }
    }

    if (wb[0] == 15 or wb[1] == 15) {
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