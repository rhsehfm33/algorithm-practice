#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    vector<array<int, 2>> ldp(n + 2);
    for (int ai = 1, bi = 0; ai <= n; ++ai) {
        ldp[ai][0] = ldp[ai - 1][0];
        if (bi < m and a[ai] >= b[bi]) {
            ++ldp[ai][0];
            ++bi;
        }
    }
    for (int ai = n, bi = m - 1; ai; --ai) {
        ldp[ai][1] = ldp[ai + 1][1];
        if (bi >= 0 and a[ai] >= b[bi]) {
            ++ldp[ai][1];
            --bi;
        }
    }

    int ans = INF;
    for (int i = 0; i <= n and ans; ++i) {
        int sum = ldp[i][0] + ldp[i + 1][1];
        if (sum >= m) {
            ans = 0;
        } else if (sum + 1 == m) {
            ans = min(ans, b[ldp[i][0]]);
        }
    }
    cout << (INF == ans ? -1 : ans) << '\n';
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