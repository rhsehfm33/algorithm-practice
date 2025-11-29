#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ab(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ab[i][j];
        }
    }

    vector<int> cnt(20), r(20);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (((ab[0][i] >> j) & 1) ^ ((ab[1][i] >> j) & 1)) {
                ++cnt[j];
                r[j] = i;
            }
        }
    }

    for (int i = 19; i >= 0; --i) {
        if (cnt[i] % 2) {
            if (r[i] % 2 == 0) {
                cout << "Ajisai\n";
                return;
            } else {
                cout << "Mai\n";
                return;
            }
        }
    }
    cout << "Tie\n";
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