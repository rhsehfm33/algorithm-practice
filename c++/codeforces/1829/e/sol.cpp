#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int get_lake_size(vector<vector<int>>& a, int x, int y) {
    if (a[x][y] == 0) {
        return 0;
    }

    int result = a[x][y];
    a[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (q.size()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (nx >= 0 and nx < a.size() and ny >= 0 and ny < a[0].size()) {
                if (a[nx][ny] != 0) {
                    result += a[nx][ny];
                    a[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    return result;
}

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            cin >> a[x][y];
        }
    }

    int ans = 0;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            ans = max(ans, get_lake_size(a, x, y));
        }
    }

    cout << ans << '\n';
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