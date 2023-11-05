#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    map<int, vector<int>> p2i;

    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> lr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> lr[i][0] >> lr[i][1];
        p2i[lr[i][0]].push_back(i);
        p2i[lr[i][1] + 1].push_back(-i);
    }

    int ans = 0, cnt = 0;
    map<int, int> p2c;
    for (auto [p, is] : p2i) {
        for (auto i : is) {
            if (i < 0) {
                --cnt;
                --p2c[lr[-i][0]];
                --p2c[lr[-i][1]];
            } else {
                ++cnt;
                ++p2c[lr[i][0]];
                ++p2c[lr[i][1]];
            }
        }
        ans = max({ans, cnt - p2c[1], cnt - p2c[m]});
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