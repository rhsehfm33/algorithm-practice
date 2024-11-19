#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    if (n == 5) {
        cout << "5\n2 1 3 4 5\n";
        return;
    }
    int k = n % 2 ? n : (1 << (int)log2(n * 2)) - 1;
    cout << k << '\n';
    for (int i = n - n % 2; i > 0; --i) {
        if (__builtin_popcount(i) != 1 and __builtin_popcount(i + 1) != 1) {
            cout << i << ' ';
        }
    }
    for (int i = 1; i <= n - n % 2; ++i) {
        if (__builtin_popcount(i) == 1 or __builtin_popcount(i + 1) == 1) {
            cout << i << ' ';
        }
    }
    if (n % 2) {
        cout << n;
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