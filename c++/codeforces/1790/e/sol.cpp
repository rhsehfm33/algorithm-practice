#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll x;
    cin >> x;

    if (x % 2 == 1) {
        cout << "-1\n";
        return;
    }

    ll a = 0, b = 0;
    for (ll i = 0; (1 << i) <= x; ++i) {
        if ((x >> i) & 1) {
            a |= (1 << i);
        }
    }

    ll x2 = x / 2;
    for (ll i = 0; (1 << i) <= x2; ++i) {
        if ((x2 >> i) & 1) {
            a |= (1 << i);
            b |= (1 << i);
        }
    }

    if ((a + b) == (a ^ b) * 2 and (a ^ b) == x) {
        cout << a << ' ' << b << '\n';
    }
    else {
        cout << "-1\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}