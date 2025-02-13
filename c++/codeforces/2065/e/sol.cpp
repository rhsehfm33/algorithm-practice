#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int bc = max(m, n);
    int sc = min(m, n);
    char bd = m >= n ? '1' : '0';
    char sd = m >= n ? '0' : '1';
    if (k > bc or k < bc - sc) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n + m; ++i) {
        if ((i / k % 2 or !bc) and sc) {
            cout << sd;
            --sc;
        } else {
            cout << bd;
            --bc;
        }
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