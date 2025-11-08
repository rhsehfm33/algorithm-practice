#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    if (!n) {
        cout << "YES\n";
        return;
    }
    while (n % 2 == 0) {
        n >>= 1;
    }
    for (int r = log2(n), l = 0; l <= r; ++l, --r) {
        if (((n >> l) & 1) != ((n >> r) & 1)
        or  (l == r and ((n >> l) & 1))) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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