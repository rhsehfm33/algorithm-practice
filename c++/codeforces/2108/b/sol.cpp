#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, x;
    cin >> n >> x;
    if (x == 0) {
        cout << (n == 1 ? -1 : (n % 2 ? n + 3 : n)) << '\n';
    } else if (x == 1) {
        cout << (n % 2 ? n : n + 3) << '\n';
    } else {
        ll r = n - __builtin_popcount(x);
        cout << x + (r > 0 ? r + r % 2 : 0) << '\n';
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