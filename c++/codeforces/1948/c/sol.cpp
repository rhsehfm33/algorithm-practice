#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<string> b(2);
    cin >> b[0] >> b[1];
    vector<vector<bool>> v(2, vector<bool>(n));

    queue<array<int, 2>> q;
    q.push({0, 0});
    v[0][0] = true;
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        if (x == 1 and y == n - 1) {
            cout << "YES\n";
            return;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 and nx < 2 and ny >= 0 and ny < n) {
                ny = b[nx][ny] == '<' ? ny - 1 : ny + 1;
                if (!v[nx][ny]) {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << "NO\n";
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