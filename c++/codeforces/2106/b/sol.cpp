#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0, l = 0, r = n - 1; i < n; ++i) {
        if (i < x) {
            cout << l++ << ' ';
        } else {
            cout << r-- << ' ';
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