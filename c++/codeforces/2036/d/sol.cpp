#include <bits/stdc++.h>

using namespace std;

int _ti;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> nm(n);
    for (auto& nmi : nm) {
        cin >> nmi;
    }

    set<pair<int, int>> s;
    for (int i = 0; i < min(n, m) / 2; ++i) {
        for (int j = 0, d = 0, cur = 0, x = i, y = i; j < 2 * (n + m - 2) + 3; ++j) {
            cur = (cur * 10 + (nm[x][y] - '0')) % 10000;
            if (cur == 1543) {
                s.insert({x, y});
            }
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < i or nx >= n - i or ny < i or ny >= m - i) {
                d = (d + 1) % 4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            x = nx;
            y = ny;
        }
    }
    cout << s.size() << '\n';
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