#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k, x;
    cin >> n >> k >> x;
    if (n < k or x < k - 1) {
        cout << -1 << '\n';
        return;
    }

    cout << k * (k - 1) / 2 + (k == x ? (k - 1) * (n - k) : x * (n - k)) << '\n';
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