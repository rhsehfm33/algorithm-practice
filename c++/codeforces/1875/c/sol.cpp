#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    n %= m;

    ll nmgcd = gcd(n, m);
    ll dm = m / nmgcd;
    ll dn = n / nmgcd;
    if (__builtin_popcount(dm) != 1) {
        cout << -1 << '\n';
        return;
    }
    ll i = __builtin_ctz(dm);

    ll ans = 0;
    for (ll j = 0; j < 30; ++j, --i) {
        if ((dn >> j) & 1) {
            ans += (1 << j) * ((1 << i) - 1);
        }
    }
    cout << ans * nmgcd << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}