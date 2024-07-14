#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int m0 = 0, m1 = 0, s = 0, a = 0, n;
    cin >> n;
    vector<vector<int>> m(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (m[0][i] == 1 and m[1][i] == 1) {
            ++a;
        } else if (m[0][i] == -1 and m[1][i] == -1) {
            ++s;
        } else if (m[0][i] == 1) {
            ++m0;
        } else if (m[1][i] == 1) {
            ++m1;
        }
    }

    while (a--) {
        if (m0 < m1) {
            ++m0;
        } else {
            ++m1;
        }
    }
    while (s--) {
        if (m0 < m1) {
            --m1;
        } else {
            --m0;
        }
    }

    cout << min(m0, m1) << '\n';
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