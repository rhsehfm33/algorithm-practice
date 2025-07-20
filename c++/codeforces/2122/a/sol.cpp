#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    if ((n >= 2 and m > 2) or (m >= 2 and n > 2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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