#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        if (i < n / 2) {
            cout << i + 1 << ' ';
        } else {
            cout << i - n / 2 + 1 << ' ';
        }
    }
    cout << (n - 1) / 2 << '\n';
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