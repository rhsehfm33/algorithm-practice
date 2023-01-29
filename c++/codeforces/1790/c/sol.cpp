#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<int>> p(n, vector<int>(n - 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cin >> p[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        int diff_count = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j and p[i][0] != p[j][0]) {
                ++diff_count;
            }
        }
        if (diff_count > 1) {
            if (i - 1 >= 0) {
                cout << p[i - 1][0] << ' ';
            }
            else {
                cout << p[i + 1][0] << ' ';
            }
            for (int pi : p[i]) {
                cout << pi << ' ';
            }
            cout << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}