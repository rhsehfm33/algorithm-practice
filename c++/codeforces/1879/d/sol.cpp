#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), s0(30), s1(30), c0(30), c1(30);
    for (ll i = 0, d = 0; i < n; ++i) {
        cin >> a[i];
        d ^= a[i];

        for (ll j = 0; j < 30; ++j) {
            if ((d >> j) & 1) {
                s1[j] = (s1[j] + (i + 1)) % MOD;
                c1[j] += 1;
            }
            else {
                s0[j] = (s0[j] + (i + 1)) % MOD;
                c0[j] += 1;
            }
        }
    }

    ll ans = 0;
    for (ll l = 0; l < n; ++l) {
        for (ll i = 0; i < 30; ++i) {
            ans = (ans + ((s1[i] * (1 << i)) % MOD)) % MOD;
        }
        for (ll i = 0; i < 30; ++i) {
            s1[i] = (s1[i] - c1[i] + MOD) % MOD;
            s0[i] = (s0[i] - c0[i] + MOD) % MOD;
            if ((a[l] >> i) & 1) {
                c1[i] -= 1;
                swap(c1[i], c0[i]);
                swap(s1[i], s0[i]);
            }
            else {
                c0[i] -= 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}