#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for (int x = 0, y = 0, d = 0, l = 0, c = n * n - 1; c > 0; --c) {
        ans[x][y] = c;
        int nx = x + dx[d % 4];
        int ny = y + dy[d % 4];
        if (nx < 0 or nx >= n or ny < 0 or ny >= n or ans[nx][ny]) {
            ++d;
            nx = x + dx[d % 4];
            ny = y + dy[d % 4];
        }
        x = nx;
        y = ny;
    }

    for (auto& xi : ans) {
        for (auto& xyi : xi) {
            cout << xyi << ' ';
        }
        cout << '\n';
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