#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    vector<string> ans(n, string(m, '.'));
    for (int y = 0; y + 1 < m; ++y) {
        int cnt = 0;
        for (int x = 0; x < n; ++x) {
            if (board[x][y] == 'L') {
                ans[x][y] = cnt % 2 ? 'W' : 'B';
                ans[x][y + 1] = cnt % 2 ? 'B' : 'W';
                ++cnt;
            }
        }
        if (cnt % 2) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int x = 0; x + 1 < n; ++x) {
        int cnt = 0;
        for (int y = 0; y < m; ++y) {
            if (board[x][y] == 'U') {
                ans[x][y] = cnt % 2 ? 'W' : 'B';
                ans[x + 1][y] = cnt % 2 ? 'B' : 'W';
                ++cnt;
            }
        }
        if (cnt % 2) {
            cout << -1 << '\n';
            return;
        }
    }

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
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