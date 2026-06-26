#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll p, q;
    cin >> p >> q;
    for (ll n = 1; 2 * n * (n + 1) <= p + 2 * q; ++n) {
        ll r = p + 2 * q - 2 * n * (n + 1);
        ll d = n * 2 + 1;
        if (r % d == 0 and p >= r / d) {
            cout << n << ' ' << n + r / d << '\n';
            return;
        }
    }
    cout << "-1\n";
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