#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2) {
        cout << l << '\n';
        return;
    }

    ll mx = 1LL << (64 - __builtin_clzll(l));
    if (mx > r or n == 2) {
        cout << "-1\n";
    } else {
        cout << (k < n - 1 ? l : mx) << '\n';
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