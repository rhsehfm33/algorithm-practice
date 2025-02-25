#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& ai : a) {
        for (auto& aij : ai) {
            cin >> aij;
        }
    }

    int mx = 0;
    vector<int> cnt(n * m + 1);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            int aij = a[x][y];
            cnt[aij] = max(cnt[aij], 1);
            mx = max(mx, 1);
            if ((x + 1 < n and aij == a[x + 1][y]) or
            (y + 1 < m and aij == a[x][y + 1])) {
                cnt[aij] = 2;
                mx = 2;
            }
        }
    }

    cout << accumulate(cnt.begin(), cnt.end(), 0) - mx << '\n';
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