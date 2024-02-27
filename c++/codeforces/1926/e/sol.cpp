#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n and k > 0; i <<= 1) {
        if (k <= (n + i) / (i * 2)) {
            cout << k * (i * 2) - i << '\n';
            return;
        }
        k -= (n + i) / (i * 2);
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