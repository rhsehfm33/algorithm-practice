#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll cal_ps(vector<ll>& ps, ll l, ll r, ll n) {
    if (l < 1) {
        return ps[r] + ps[n] - ps[l + n - 1];
    } else if (r > n) {
        return ps[r - n] + ps[n] - ps[l - 1];
    } else {
        return ps[r] - ps[l - 1];
    }
}

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n + 1), ps(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = a[i] + ps[i - 1];
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll added = a[i] * (d * 2 + 1) - cal_ps(ps, i - d, i + d, n);
        if (added > 0) {
            ans += added;
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