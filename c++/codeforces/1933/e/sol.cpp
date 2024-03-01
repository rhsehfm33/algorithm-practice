#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll get_inc(ll s, ll mx) {
    ll mn = mx + 1 - s;
    return (mx + mn) * (mx - mn + 1) / 2;
}

void solve() {
    ll n, q;
    cin >> n;
    vector<ll> ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }

    cin >> q;
    while (q--) {
        ll l, u;
        cin >> l >> u;

        ll ti = lower_bound(ps.begin() + l, ps.end(), u + ps[l - 1]) - ps.begin();
        ll v1 = ti <= n ? get_inc(ps[ti] - ps[l - 1], u) : numeric_limits<ll>::min();
        ll v2 = ti - 1 >= l ? get_inc(ps[ti - 1] - ps[l - 1], u) : numeric_limits<ll>::min();
        if (v2 >= v1) {
            cout << ti - 1 << ' ';
        } else {
            cout << ti << ' ';
        }
    }
    cout << '\n';
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