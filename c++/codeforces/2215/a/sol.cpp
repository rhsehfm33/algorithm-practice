#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<ll> a(n), ldp(n), rdp(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (ll i = 0; i < n - k; ++i) {
        ldp[i + 1] = ldp[i] + min(a[i] % p % q, a[i] % q % p);
    }
    for (ll i = n - 1; i >= k; --i) {
        rdp[i - 1] = rdp[i] + min(a[i] % p % q, a[i] % q % p);
    }

    ll s0 = 0, s1 = 0, ans = 1e18;
    for (ll i = 0; i < n; ++i) {
        s0 += (a[i] % p % q);
        s1 += (a[i] % q % p);
        if (i < k - 1) {
            continue;
        }
        if (i >= k) {
            s0 -= (a[i - k] % p % q);
            s1 -= (a[i - k] % q % p);
        }
        ans = min(ans, min(s0, s1) + rdp[i] + ldp[i - k + 1]);
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