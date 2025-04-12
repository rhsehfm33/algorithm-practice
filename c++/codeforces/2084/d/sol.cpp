#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n - m * k <= k) {
        for (int i = 0; i < n; ++i) {
            cout << i % k << ' ';
        }
    } else {
        int nk = n / (m + 1);
        for (int i = 0; i < n; ++i) {
            cout << i % nk << ' ';
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