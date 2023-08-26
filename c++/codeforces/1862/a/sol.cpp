#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            cin >> c[x][y];
        }
    }

    int ti = 0;
    string target = "vika";
    for (int y = 0; y < m and ti < 4; ++y) {
        for (int x = 0; x < n and ti < 4; ++x) {
            if (c[x][y] == target[ti]) {
                ++ti;
                break;
            }
        }
    }

    if (ti == 4) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}