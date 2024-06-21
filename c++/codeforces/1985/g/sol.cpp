#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int _ti;

ll mul(ll n1, ll n2) {
    return (n1 * n2) % MOD;
}

ll sub(ll n1, ll n2) {
    return (n1 - n2 + MOD) % MOD;
}

ll cal(ll n, ll p) {
    ll r = 1;
    for (ll i = 1, c = n; i <= p; i <<= 1, c = mul(c, c)) {
        if (p & i) {
            r = mul(r, c);
        }
    }
    return r;
}

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    if (k >= 10) {
        cout << "0\n";
    } else {
        cout << sub(cal(9 / k + 1, r), cal(9 / k + 1, l)) << '\n';
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