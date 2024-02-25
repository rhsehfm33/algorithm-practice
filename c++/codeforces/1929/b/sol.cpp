#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    if (k <= 4 * n - 4) {
        cout << k / 2 + k % 2 << '\n';
    } else {
        cout << (n - 1) * 2 + k - (4 * n - 4) << '\n';
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