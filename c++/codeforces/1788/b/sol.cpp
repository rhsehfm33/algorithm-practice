#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;

    ll a = 0, b = 0;
    for (ll p10 = 1, is_a = 1; n; p10 *= 10, n /= 10) {
        a += p10 * (n % 10 / 2);
        b += p10 * (n % 10 / 2);
        if (n % 2) {
            if (is_a) {
                a += p10 * (n % 2);
            }
            else {
                b += p10 * (n % 2);
            }
            is_a ^= 1;
        }
    }

    cout << a << ' ' << b << '\n';
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