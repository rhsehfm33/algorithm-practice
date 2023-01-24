#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    int s = 1, b = n * n;
    for (int y = 0; y < 2 * n; ++y) {
        for (int cy = y, cx = 0; cx < n and cy >= 0; ++cx, --cy) {
            if (cy >= n) {
                continue;
            }
            if ((cx + cy) % 2 == 0) {
                ans[cx][cy] = s++;
            }
            else {
                ans[cx][cy] = b--;
            }
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cout << ans[x][y] << ' ';
        }
        cout << '\n';
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