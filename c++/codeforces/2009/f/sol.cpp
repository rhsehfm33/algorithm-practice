#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll sum(vector<ll>& ps, ll n, ll i) {
    ll r = i / n * ps[n];
    if (i % n) {
        r += ps[i / n + i % n] - ps[i / n];
    }
    return r;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> ps(n + n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    for (ll i = n + 1; i <= n + n; ++i) {
        ps[i] = ps[i - 1] + ps[i - n] - ps[i - n - 1];
    }

    while (q--) {
        ll l, r, ans = 0;
        cin >> l >> r;
        cout << sum(ps, n, r) - sum(ps, n, l - 1) << '\n';
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