#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n % MOD << '\n';
        return;
    }

    ll i = 3;
    ll n1 = 1, n2 = 1;
    while ((n1 + n2) % k) {
        n2 = (n1 + n2) % k;
        n1 = (n2 - n1 + k) % k;
        ++i;
    }

    ll ans = 0;
    for (ll b = 1; b <= n; b <<= 1, i = (i * 2) % MOD) {
        if (b & n) {
            ans = (ans + i) % MOD;
        }
    }
    cout << ans << '\n';
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