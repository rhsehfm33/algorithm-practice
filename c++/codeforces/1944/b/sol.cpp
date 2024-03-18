#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    vector<vector<int>> ans(2);

    int n, k;
    cin >> n >> k;
    vector<set<int>> s(2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0, ai; j < n; ++j) {
            cin >> ai;
            s[i].insert(ai);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= n and ans[i].size() < 2 * k; ++j) {
            if (s[i].count(j) and !s[i ^ 1].count(j)) {
                ans[i].push_back(j);
                ans[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n and ans[0].size() < 2 * k; ++i) {
        if (s[0].count(i) and s[1].count(i)) {
            ans[0].push_back(i);
            ans[1].push_back(i);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2 * k; ++j) {
            cout << ans[i][j] << ' ';
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