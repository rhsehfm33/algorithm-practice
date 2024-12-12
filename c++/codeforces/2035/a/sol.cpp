#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    long long n, m, r, c;
    cin >> n >> m >> r >> c;
    cout << (n - r) * (m + m - 1) + (m - c) << '\n';
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