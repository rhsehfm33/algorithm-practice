#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> ans(n, INT_MAX);
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
            if (i != j) {
                ans[i] &= M[i][j];
            }
        }
    }

    if (n == 1) {
        cout << "Yes\n0\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (M[i][j] != (ans[i] | ans[j])) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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