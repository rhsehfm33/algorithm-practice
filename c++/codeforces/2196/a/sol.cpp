#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll p, q;
    cin >> p >> q;
    ll d = 3 * p - 2 * q;
    if (d >= 0 and p - d >= 2 and q - d >= 3) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
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