#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (i <= n / 2) {
            cout << (n - i * 2) << ' ';
        } else {
            cout << (i - n / 2) * 2 << ' ';
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