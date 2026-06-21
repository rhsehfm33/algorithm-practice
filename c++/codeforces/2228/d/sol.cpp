#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> sy;
    vector<array<int, 2>> xy(n);
    for (auto& [x, y] : xy) {
        cin >> x >> y;
        sy.push_back(y);
    }
    sort(xy.begin(), xy.end());
    sort(sy.begin(), sy.end());
    sy.erase(unique(sy.begin(), sy.end()), sy.end());

    vector<array<int, 2>> ry(n + 1);
    ry[n][0] = 1e9, ry[n][1] = -1;
    for (int i = n - 1; i >= 0; --i) {
        ry[i][0] = min(xy[i][1], ry[i + 1][0]);
        ry[i][1] = max(xy[i][1], ry[i + 1][1]);
    }

    long long ans = 0;
    for (int i = 0, j = 0, lmn = 1e9, lmx = -1; i < n; i = j) {
        while (j < n and xy[i][0] == xy[j][0]) {
            lmn = min(lmn, xy[j][1]);
            lmx = max(lmx, xy[j][1]);
            ++j;
        }
        if (j == n) {
            break;
        }
        int from = lower_bound(sy.begin(), sy.end(), max(lmn, ry[j][0])) - sy.begin();
        int to = lower_bound(sy.begin(), sy.end(), min(lmx, ry[j][1])) - sy.begin();
        ans += max(0, to - from);
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