#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;

    vector<vector<int>> ans(2, vector<int>(n));
    for (int y = 0; y < n; ++y) {
        if (y % 2 == 0) {
            ans[0][y] = n * 2 - y;
            ans[1][y] = y + 1;
        }
        else {
            ans[0][y] = y + 1;
            ans[1][y] = n + y;
        }
    }

    for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < n; ++y) {
            cout << ans[x][y] << ' ';
        }
        cout << '\n';
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