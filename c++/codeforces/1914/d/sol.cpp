#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> abc(3, vector<array<int, 2>>(n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> abc[i][j][0];
            abc[i][j][1] = j;
        }
        sort(abc[i].begin(), abc[i].end(), greater<array<int, 2>>());
    }

    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                int ai = abc[0][i][1];
                int bi = abc[1][j][1];
                int ci = abc[2][k][1];
                if (ai == bi or ai == ci or bi == ci) {
                    continue;
                }
                ans = max(ans, abc[0][i][0] + abc[1][j][0] + abc[2][k][0]);
            }
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