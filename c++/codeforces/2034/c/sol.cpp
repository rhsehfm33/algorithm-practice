#include <bits/stdc++.h>

using namespace std;

int _ti;

bool in(char xy) {
    return xy == '?' or xy == 'x';
}

char out(vector<vector<char>>& g, int x, int y) {
    if (g[x][y] == '.') {
        return '.';
    }
    if (g[x][y] == '?' or g[x][y] == 'x') {
        return 'x';
    }

    char d = g[x][y];
    g[x][y] = 'x';
    if (d == 'U') {
        g[x][y] = out(g, x - 1, y);
    } else if (d == 'R') {
        g[x][y] = out(g, x, y + 1);
    } else if (d == 'D') {
        g[x][y] = out(g, x + 1, y);
    } else if (d == 'L') {
        g[x][y] = out(g, x, y - 1);
    }
    return g[x][y];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 2, vector<char>(m + 2, '.'));
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            cin >> g[x][y];
        }
    }

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            out(g, x, y);
        }
    }

    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            if (g[x][y] == 'x') {
                ++ans;
            } else if (g[x][y] == '?') {
                if (in(g[x - 1][y]) or in(g[x][y - 1]) or in(g[x + 1][y]) or in(g[x][y + 1])) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
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