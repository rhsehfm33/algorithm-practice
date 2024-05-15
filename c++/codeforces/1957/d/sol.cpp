#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void change(vector<array<ll, 2>>& xs, ll x, ll d) {
    for (ll i = 0; i < 31; ++i) {
        xs[i][(x >> i) & 1] += d;
    }
}

void solve() {
    vector<array<ll, 2>> lxs(32), rxs(32);

    ll n, ans = 0, lx = 0, rx = 0;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        lx ^= a[i];
        change(lxs, lx, 1);
    }

    for (ll i = n - 1, all = lx; i >= 0; --i) {
        change(lxs, lx, -1);
        lx ^= a[i];
        ll b = log2(a[i]);
        if (all & (1 << b)) {
            ans += lxs[b][1] * (rxs[b][0] + 1) + (lxs[b][0] + 1) * rxs[b][1];
        } else {
            ans += (lxs[b][0] + 1) * (rxs[b][0] + 1) + lxs[b][1] * rxs[b][1];
        }
        rx ^= a[i];
        change(rxs, rx, 1);
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