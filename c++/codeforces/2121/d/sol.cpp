#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ab(3, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> ab[1][i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> ab[2][i];
    }

    vector<array<int, 2>> ans;
    for (int i = 1; i <= n; ++i) {
        if (ab[1][i] > ab[2][i]) {
            swap(ab[1][i], ab[2][i]);
            ans.push_back({3, i});
        }
    }
    for (int i = 1; i <= 2; ++i) {
        for (int j = n - 1; j; --j) {
            for (int j2 = j; j2 < n; ++j2) {
                if (ab[i][j2] > ab[i][j2 + 1]) {
                    swap(ab[i][j2], ab[i][j2 + 1]);
                    ans.push_back({i, j2});
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [t, i] : ans) {
        cout << t << ' ' << i << '\n';
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