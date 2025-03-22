#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll get_height(ll b2) {
    ll l = 0, h = 2e5;
    while (l <= h) {
        ll m = (l + h) / 2;
        if (m * m <= b2) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return h;
}

void solve() {
    map<ll, ll> mx;
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), r(n);
    for (auto& xi : x) {
        cin >> xi;
    }
    for (auto& ri : r) {
        cin >> ri;
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = -r[i]; j <= r[i]; ++j) {
            ll p = x[i] + j;
            ll b = get_height(r[i] * r[i] - abs(j * j));
            if (!mx.count(p)) {
                ans += b * 2 + 1;
                mx[p] = b;
            } else if (b > mx[p]) {
                ans += (b - mx[p]) * 2;
                mx[p] = b;
            }
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