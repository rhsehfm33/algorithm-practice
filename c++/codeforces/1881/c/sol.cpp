#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int a = 0; a < n / 2; ++a) {
        for (int b = a; b < n - a - 1; ++b) {
            int c1 = board[a][b];
            int c2 = board[b][n - a - 1];
            int c3 = board[n - a - 1][n - b - 1];
            int c4 = board[n - b - 1][a];
            int mx = max({c1, c2, c3, c4});
            ans += (mx - c1) + (mx - c2) + (mx - c3) + (mx - c4);
        }
    }
    cout << ans << '\n';
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