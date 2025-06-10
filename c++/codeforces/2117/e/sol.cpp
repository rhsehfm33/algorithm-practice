#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> ab(n), p(n + 1), pp(n + 1);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ab[j][i];
        }
    }

    int ans = 0;
    for (int i = 0, u, d; i < n; ++i) {
        auto [un, dn] = ab[i];
        u = i & 1;
        d = (i + 1) & 1;
        ans = max({ans, p[un][d], pp[un][u]});
        ans = max({ans, p[dn][u], pp[dn][d]});
        if (un == dn) {
            ans = i + 1;
        }
        p[un][u] = i + 1;
        p[dn][d] = i + 1;
        if (i) {
            pp[ab[i - 1][0]][d] = i;
            pp[ab[i - 1][1]][u] = i;
        }
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