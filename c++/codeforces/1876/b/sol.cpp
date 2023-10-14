#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> tp(n + 1);
    for (ll i = 0, j = 1; i <= n; ++i, j = (j * 2) % MOD) {
        tp[i] = j;
    }

    vector<ll> cnt(1e5 + 1);
    for (ll i = 0; i < n; ++i) {
        ll mx = 0;
        for (ll j = i; j < n; j += i + 1) {
            mx = max(mx, a[j]);
        }
        ++cnt[mx];
    }

    ll ans = 0;
    for (ll i = 1e5, sum = n; i > 0; --i) {
        if (cnt[i]) {
            sum -= cnt[i];
            ll cases = ((((tp[cnt[i]] - 1 + MOD) % MOD) * tp[sum]) % MOD) * i % MOD;
            ans = (ans + cases) % MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}