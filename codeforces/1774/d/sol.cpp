#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c1(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                ++c1[i];
            }
        }
    }

    int sum1 = accumulate(c1.begin(), c1.end(), 0);
    if (sum1 % n) {
        cout << "-1\n";
        return;
    }

    int div = sum1 / n;
    vector<array<int, 3>> ans;
    for (int j = 0; j < m; ++j) {
        int b1 = 0, s1 = 0;

        while (true) {
            while (b1 < n) {
                if (c1[b1] > div and a[b1][j]) {
                    break;
                }
                ++b1;
            }
            while (s1 < n) {
                if (c1[s1] < div and a[s1][j] == 0) {
                    break;
                }
                ++s1;
            }

            if (b1 < n and s1 < n) {
                ans.push_back({s1 + 1, b1 + 1, j + 1});
                ++c1[s1];
                --c1[b1];
                ++s1;
                ++b1;
            }
            else {
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y, z] : ans) {
        cout << x << ' ' << y << ' ' << z << '\n';
    }
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