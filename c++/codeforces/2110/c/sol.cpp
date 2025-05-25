#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n), ps(n), sr(n, n - 1);
    for (auto& di : d) {
        cin >> di;
    }
    vector<array<int, 2>> h(n);
    for (auto& [l, r] : h) {
        cin >> l >> r;
    }

    ps[0] = d[0] == 1;
    for (int i = 1; i < n; ++i) {
        ps[i] = ps[i - 1] + (d[i] == 1);
    }
    for (int i = n - 2; i >= 0; --i) {
        sr[i] = h[i][1] - ps[i] < h[sr[i + 1]][1] - ps[sr[i + 1]] ? i : sr[i + 1];
    }

    for (int i = 0, s = 0; i < n; ++i) {
        if (d[i] == -1) {
            if (s + ps[sr[i]] - ps[i] < h[sr[i]][1]) {
                d[i] = 1;
            } else {
                d[i] = 0;
            }
        }
        s += d[i];
        if (s < h[i][0] or s > h[i][1]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto& di : d) {
        cout << di << ' ';
    }
    cout << '\n';
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